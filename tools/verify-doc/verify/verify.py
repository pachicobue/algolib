import subprocess
import sys
import os
import hashlib
import traceback
import resource
from logging import getLogger
from pathlib import Path
import onlinejudge
import onlinejudge.dispatch
import onlinejudge.service
import onlinejudge.service.library_checker

sys.path.append(str(Path(__file__).parent.resolve()))
sys.path.append(str(Path(__file__).parent.parent.resolve()))
from common.verif_status_register import (
    VerifStatus,
    mark_status,
    refer_status,
)
from common.config import *
from common.result import VerifResult
from common.dependency import get_dependency
from common.util import get_last_modified_time
from attribute import get_atrribute

_logger = getLogger(__name__)


def _compile(verif_path: Path, directory: Path) -> bool:
    directory.mkdir(parents=True, exist_ok=True)
    command = (
        [compile_command] + compile_flags + ["-o", directory / "a.out", str(verif_path)]
    )  # [str]
    try:
        print(command)
        subprocess.check_call(command)
    except Exception:
        traceback.print_exc()
        return False
    return True


def _download(url: str, directory: Path) -> bool:
    if not (directory / "test").exists():
        directory.mkdir(parents=True, exist_ok=True)
        subprocess.check_call(["sleep", "2"])
        command = [
            "oj",
            "download",
            "--system",
            "-d",
            str(directory / "test"),
            "--silent",
            url,
        ]
        if os.environ.get("YUKICODER_TOKEN"):
            command += ["--yukicoder-token", os.environ["YUKICODER_TOKEN"]]
        try:
            subprocess.check_output(command)
        except Exception:
            traceback.print_exc()
            return False
    return True


def _test(
    verif_path: Path,
    tle: float,
    error: Optional[str],
    url: str,
    directory: Path,
) -> bool:
    _, hard = resource.getrlimit(resource.RLIMIT_STACK)
    resource.setrlimit(resource.RLIMIT_STACK, (hard, hard))

    problem = onlinejudge.dispatch.problem_from_url(url)
    command = [
        "oj",
        "test",
        "-c",
        directory / "a.out",
        "-d",
        str(directory / "test"),
        "--tle",
        str(tle),
        "--silent",
    ]
    if isinstance(problem, onlinejudge.service.library_checker.LibraryCheckerProblem):
        command += ["--judge-command", str(problem.download_checker_binary())]
    if error:
        command += ["--error", error]
    try:
        subprocess.check_output(command)
    except Exception:
        traceback.print_exc()
        return False
    return True


def _test_unittest(
    verif_path: Path,
    tle: float,
    directory: Path,
) -> bool:
    _, hard = resource.getrlimit(resource.RLIMIT_STACK)
    resource.setrlimit(resource.RLIMIT_STACK, (hard, hard))

    command = [
        directory / "a.out",
    ]
    try:
        subprocess.check_call(command, timeout=tle)
    except Exception:
        traceback.print_exc()
        return False
    return True


def _verify(verif_path: Path, tle: float) -> VerifResult:
    attributes = get_atrribute(verif_path)
    if attributes.ignore:
        return VerifResult.SKIPPED
    if attributes.unittest:
        directory = verify_workspace_dir / "cache"
        if not _compile(verif_path, directory):
            return VerifResult.CE
        if not _test_unittest(verif_path, tle, directory):
            return VerifResult.WA_TLE_RE
        return VerifResult.AC
    else:
        url = attributes.problem
        if url == None:
            return VerifResult.CE
        directory = (
            verify_workspace_dir / "cache" / hashlib.md5(url.encode()).hexdigest()
        )
        if not _download(url, directory):
            return VerifResult.CE
        if not _compile(verif_path, directory):
            return VerifResult.CE
        if not _test(verif_path, tle, attributes.error, url, directory):
            return VerifResult.WA_TLE_RE
        return VerifResult.AC


def check_verify_register(verif_path: Path, tle: float) -> None:
    _logger.info("check_verify_register: {}".format(verif_path))
    status = refer_status(verif_path)
    try:
        dependency = get_dependency(verif_path)
    except Exception:
        last_modified_date = get_last_modified_time([verif_path])
        mark_status(verif_path, VerifStatus(last_modified_date, VerifResult.CE))
    else:
        last_modified_date = get_last_modified_time(dependency)
        if last_modified_date > status.date:
            _logger.info("Verify start")
            result = _verify(verif_path, tle)
            mark_status(verif_path, VerifStatus(last_modified_date, result))
        else:
            _logger.info("No need to verify")
