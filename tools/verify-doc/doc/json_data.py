import sys
import json
from typing import *
from pathlib import Path

sys.path.append(str(Path(__file__).parent.resolve()))
sys.path.append(str(Path(__file__).parent.parent.resolve()))
from common.config import *
from common.util import get_verif_list, get_src_list
from code_info import SrcCodeInfo, VerifCodeInfo
from code_info_register import refer_src_code_info, refer_verif_code_info


def _save_src_json():
    alldict: Dict[str, Dict[str, Any]] = {}
    for src_path in get_src_list():
        src_code_info = refer_src_code_info(src_path)
        dict: Dict[str, Any] = {}
        dict["result"] = src_code_info.result.name
        dict["verified_with"] = [
            str(f.relative_to(library_root_dir)) for f in src_code_info.verified_with
        ]
        dict["code"] = src_code_info.code
        alldict[str(src_path.relative_to(source_dir))] = dict
    output_path = src_data_json
    output_path.parent.mkdir(parents=True, exist_ok=True)
    with open(output_path, "w") as f:
        json.dump(alldict, f, sort_keys=True, indent=4)


def _save_verif_json():
    alldict: Dict[str, Dict[str, Any]] = {}
    for verif_path in get_verif_list():
        verif_code_info = refer_verif_code_info(verif_path)
        dict: Dict[str, Any] = {}
        dict["result"] = verif_code_info.result.name
        dict["code"] = verif_code_info.code
        alldict[str(verif_path.relative_to(verification_dir))] = dict
    output_path = verif_data_json
    output_path.parent.mkdir(parents=True, exist_ok=True)
    with open(output_path, "w") as f:
        json.dump(alldict, f, sort_keys=True, indent=4)


def save_json():
    _save_verif_json()
    _save_src_json()
