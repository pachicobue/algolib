from pathlib import Path
import sys
import re
from typing import *

sys.path.append(str(Path(__file__).parent.resolve()))
sys.path.append(str(Path(__file__).parent.parent.resolve()))
from common.config import *

_pattern = re.compile(r"\bverification-helper:\s*([0-9A-Z_]+)(?:\s(.*))?$")

PROBLEM: str = "PROBLEM"
ERROR: str = "ERROR"
IGNORE: str = "IGNORE"
UNITTEST: str = "UNITTEST"


def get_atrribute(verif_path: Path) -> Dict[str, str]:
    attributes = {}
    with open(verif_path) as f:
        for line in f:
            matched = _pattern.search(line)
            if matched:
                key = matched.group(1)
                value = (matched.group(2) or "").strip()
                attributes[key] = value
    return attributes
