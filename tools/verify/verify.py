import subprocess
import sys
import os
import hashlib
import traceback
from glob import glob
from datetime import datetime, timezone
from pathlib import Path
import onlinejudge
import onlinejudge.dispatch
import onlinejudge.service
import onlinejudge.service.library_checker

sys.path.append(str(Path(__file__).parent.resolve()))
sys.path.append(str(Path(__file__).parent.parent.resolve()))
from common.status_register import (
    VerifStatus,
    mark_status,
    refer_status,
    error_timestamp,
)
from common.config import *
from common.result import VerifResult
from attribute import get_atrribute, PROBLEM, UNITTEST, ERROR, IGNORE
from dependency import get_dependency


def _compile(verif_path: Path, directory: Path) -> bool:
    command = (
        [compile_command] + compile_flags + ["-o", directory / "a.out", str(verif_path)]
    )  # [str]
    try:
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
    problem = onlinejudge.dispatch.problem_from_url(url)
    command = [
        "oj",
        "test",
        "-c",
        (directory / "a.out").resolve(),
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
    command = [
        (directory / "a.out").resolve(),
    ]
    try:
        subprocess.check_call(command, timeout=tle)
    except Exception:
        traceback.print_exc()
        return False
    return True


def _verify(verif_path: Path, tle: float) -> VerifResult:
    attributes = get_atrribute(verif_path)
    if IGNORE in attributes:
        return VerifResult.SKIPPED
    if UNITTEST in attributes:
        directory = verif_workspace / "cache"
        if not _compile(verif_path, directory):
            return VerifResult.WRONG_TEST
        if not _test_unittest(verif_path, tle, directory):
            return VerifResult.WA_TLE_RE
        return VerifResult.AC
    else:
        url = attributes[PROBLEM]
        directory = verif_workspace / "cache" / hashlib.md5(url.encode()).hexdigest()
        if not _download(url, directory):
            return VerifResult.WRONG_TEST
        if not _compile(verif_path, directory):
            return VerifResult.WRONG_TEST
        if not _test(verif_path, tle, attributes.get("ERROR"), url, directory):
            return VerifResult.WA_TLE_RE
        return VerifResult.AC


def check_verify_register(verif_path: Path, tle: float) -> None:
    status = refer_status(verif_path)
    try:
        dependency = get_dependency(verif_path)
    except Exception:
        mark_status(verif_path, VerifStatus(error_timestamp, VerifResult.WRONG_TEST))
    else:
        last_modified_date = (
            datetime.fromtimestamp(
                max([x.stat().st_mtime for x in dependency]),
                tz=datetime.now(timezone.utc).astimezone().tzinfo,
            ).replace(microsecond=0)
            if len(dependency) > 0
            else error_timestamp
        )
        if last_modified_date > status.date:
            print(
                "{}: Start verification".format(
                    verif_path.relative_to(verification_dir)
                )
            )
            result = _verify(verif_path, tle)
            mark_status(verif_path, VerifStatus(last_modified_date, result))
        else:
            print(
                "{}: No need to verify".format(verif_path.relative_to(verification_dir))
            )


def get_verif_list() -> List[Path]:
    return list(
        map(Path, glob("**/*.test.cpp", recursive=True, root_dir=verification_dir))
    )
