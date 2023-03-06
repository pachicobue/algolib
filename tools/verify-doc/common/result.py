from enum import Enum


class VerifResult(Enum):
    AC = "AC"
    WA_TLE_RE = "WA_TLE_RE"
    CE = "CE"
    SKIPPED = "SKIPPED"
    INVALID = "INVALID"  # これがjsonに記録されることはないはず


class SrcResult(Enum):
    ALL_AC = "ALL_AC"
    SOME_WA_TLE_RE = "SOME_WA_TLE_RE"
    NOT_TESTED = "NOT_TESTED"
