import sys
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
from json_data import save_src_json, save_verif_json

_logger = getLogger(__name__)

_verif_code_infos: Dict[Path, VerifCodeInfo] = {}
_src_code_infos: Dict[Path, SrcCodeInfo] = {}


def get_verif_code_info(verif_path: Path) -> None:
    _logger.info("get_verif_code_info: {}".format(verif_path))
    verif_info = _verif_code_infos.setdefault(verif_path, VerifCodeInfo())
    verif_info.result = refer_status(verif_path).result
    with open(verif_path) as f:
        verif_info.code = f.read()
    for src_path in get_dependency(verif_path):
        src_info = _src_code_infos.setdefault(src_path, SrcCodeInfo())
        src_info.verified_with.append(verif_path)
    save_verif_json(verif_path, verif_info)


def get_src_code_info(src_path: Path) -> None:
    _logger.info("get_src_code_info: {}".format(src_path))
    src_info = _src_code_infos.setdefault(src_path, SrcCodeInfo())
    dict: Dict[VerifResult, int] = {}
    for verif_path in src_info.verified_with:
        verif_result = _verif_code_infos[verif_path].result
        dict.setdefault(verif_result, dict.get(verif_result, 0) + 1)
    ac = dict.get(VerifResult.AC, 0)
    wa_tle_re = dict.get(VerifResult.WA_TLE_RE, 0)
    if wa_tle_re > 0:
        src_info.result = SrcResult.SOME_WA_TLE_RE
    elif ac > 0:
        src_info.result = SrcResult.ALL_AC
    else:
        src_info.result = SrcResult.NOT_TESTED
    with open(src_path) as f:
        src_info.code = f.read()
    save_src_json(src_path, src_info)
