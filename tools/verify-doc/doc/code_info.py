import sys
from typing import *
from pathlib import Path

sys.path.append(str(Path(__file__).parent.resolve()))
sys.path.append(str(Path(__file__).parent.parent.resolve()))
from common.config import *
from common.result import VerifResult, SrcResult


class VerifCodeInfo:
    def __init__(self):
        self.result = VerifResult.INVALID
        self.code: str = ""


class SrcCodeInfo:
    def __init__(self):
        self.result = SrcResult.NOT_TESTED
        self.verified_with: List[Path] = []
        self.code: str = ""
