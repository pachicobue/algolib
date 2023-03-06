import subprocess
import shlex
import sys
from pathlib import Path
from typing import *

sys.path.append(str(Path(__file__).parent.resolve()))
sys.path.append(str(Path(__file__).parent.parent.resolve()))
from config import *


def get_dependency(verif_path: Path) -> List[Path]:
    command = [compile_command, "-MM", str(verif_path)] + compile_flags  # [str]
    data = subprocess.check_output(command)
    makefile_rule = shlex.split(
        data.decode().strip().replace("\\\n", "").replace("\\\r\n", "")
    )
    return [Path(path).resolve() for path in makefile_rule[1:]]
