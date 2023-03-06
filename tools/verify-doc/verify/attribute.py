from pathlib import Path
import sys
import re
from typing import *

sys.path.append(str(Path(__file__).parent.resolve()))
sys.path.append(str(Path(__file__).parent.parent.resolve()))
from common.config import *

_special_comment_pattern = re.compile(
    r"\bverification-helper:\s*([0-9A-Z_]+)(?:\s(.*))?$"
)


class VerifAttribute:
    def __init__(self, dict: Dict[str, str]):
        self.ignore = "IGNORE" in dict
        self.unittest = "UNITTEST" in dict
        self.problem = dict.get("PROBLEM")
        self.error = dict.get("ERROR")


def get_atrribute(verif_path: Path) -> VerifAttribute:
    dict = {}
    with open(verif_path) as f:
        for line in f:
            matched = _special_comment_pattern.search(line)
            if matched:
                key = matched.group(1)
                value = (matched.group(2) or "").strip()
                dict[key] = value
    return VerifAttribute(dict)
