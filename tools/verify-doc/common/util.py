import sys
import os
from typing import *
from pathlib import Path

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
