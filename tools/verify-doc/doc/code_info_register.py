import sys
from collections import defaultdict
from logging import getLogger
from typing import *
from pathlib import Path

sys.path.append(str(Path(__file__).parent.resolve()))
sys.path.append(str(Path(__file__).parent.parent.resolve()))
from common.config import *
from common.result import VerifResult, SrcResult
from common.dependency import get_dependency
from common.verif_status_register import refer_status
from code_info import SrcCodeInfo, VerifCodeInfo

_logger = getLogger(__name__)

_verif_code_infos: Dict[Path, VerifCodeInfo] = {}
_src_code_infos: Dict[Path, SrcCodeInfo] = {}


def calc_verif_code_info(verif_path: Path) -> None:
    verif_info = _verif_code_infos.setdefault(verif_path, VerifCodeInfo())
    verif_info.result = refer_status(verif_path).result
    with open(verif_path) as f:
        verif_info.code = f.read()
    for src_path in get_dependency(verif_path):
        src_info = _src_code_infos.setdefault(src_path, SrcCodeInfo())
        src_info.verified_with.append(verif_path)


def refer_verif_code_info(verif_path: Path) -> VerifCodeInfo:
    return _verif_code_infos[verif_path]


def calc_src_code_info(src_path: Path) -> None:
    _logger.info("get_src_code_info: {}".format(src_path))
    src_info = _src_code_infos.setdefault(src_path, SrcCodeInfo())
    dict: DefaultDict[str, int] = defaultdict(int)
    for verif_path in src_info.verified_with:
        verif_result = _verif_code_infos[verif_path].result
        dict[verif_result.value] += 1
    ac: int = dict["AC"]
    wa_tle_re: int = dict["WA_TLE_RE"]
    if wa_tle_re > 0:
        src_info.result = SrcResult.SOME_WA_TLE_RE
    elif ac > 0:
        src_info.result = SrcResult.ALL_AC
    else:
        src_info.result = SrcResult.NOT_TESTED
    with open(src_path) as f:
        src_info.code = f.read()


def refer_src_code_info(src_path: Path) -> SrcCodeInfo:
    return _src_code_infos[src_path]
