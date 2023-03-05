import sys
import os
from typing import *
from pathlib import Path

sys.path.append(str(Path(__file__).parent.resolve()))
from config import *


def is_local_execution() -> bool:
    return "GITHUB_ACTION" not in os.environ


def get_json() -> Path:
    return local_json if is_local_execution() else remote_json
