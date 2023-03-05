from enum import Enum


class VerifResult(Enum):
    AC = "AC"
    WA_TLE_RE = "WA_TLE_RE"
    WRONG_TEST = "WRONG_TEST"
    SKIPPED = "SKIPPED"
    INVALID = "INVALID"  # これがjsonに記録されることはないはず
