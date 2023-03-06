import sys
import os
import subprocess
from typing import *
from pathlib import Path
from datetime import datetime, timezone

sys.path.append(str(Path(__file__).parent.resolve()))
from config import *


def _is_local_execution() -> bool:
    return "GITHUB_ACTION" not in os.environ


def _is_not_excluded_src(path: Path) -> bool:
    return not any(map(lambda f: path.is_relative_to(f), exclude_src_paths))


def get_json() -> Path:
    return verify_local_json if _is_local_execution() else verify_remote_json


def get_verif_list() -> List[Path]:
    return [(verification_dir / f) for f in verification_dir.glob("**/*.test.cpp")]


def get_src_list() -> List[Path]:
    return list(
        filter(
            _is_not_excluded_src,
            [(source_dir / f) for f in source_dir.glob("**/*.hpp")],
        )
    )


def get_last_modified_time(paths: List[Path]) -> datetime:
    if _is_local_execution():
        return datetime.fromtimestamp(
            max([x.stat().st_mtime for x in paths]),
            tz=datetime.now(timezone.utc).astimezone().tzinfo,
        ).replace(microsecond=0)
    else:
        command = ["git", "log", "-1", "--date=iso", "--pretty=%ad", "--"] + list(
            map(str, paths)
        )
        timestamp = subprocess.check_output(command).decode().strip()
        return datetime.strptime(timestamp, "%Y-%m-%d %H:%M:%S %z")
