import sys
import json
from typing import *
from pathlib import Path

sys.path.append(str(Path(__file__).parent.resolve()))
sys.path.append(str(Path(__file__).parent.parent.resolve()))
from common.config import *
from code_info import SrcCodeInfo, VerifCodeInfo


def save_src_json(src_path: Path, src_code_info: SrcCodeInfo):
    dict: Dict[str, Any] = {}
    dict["result"] = src_code_info.result.name
    dict["verified_with"] = [
        str(f.relative_to(library_root_dir)) for f in src_code_info.verified_with
    ]
    dict["code"] = src_code_info.code

    output_path = doc_data_dir / src_path.relative_to(library_root_dir).with_suffix(
        ".json"
    )
    output_path.parent.mkdir(parents=True, exist_ok=True)
    with open(output_path, "w") as f:
        json.dump(dict, f, sort_keys=True, indent=4)


def save_verif_json(verif_path: Path, verif_code_info: VerifCodeInfo):
    dict: Dict[str, str] = {}
    dict["result"] = verif_code_info.result.name
    dict["code"] = verif_code_info.code
    output_path = doc_data_dir / verif_path.relative_to(library_root_dir).with_suffix(
        ".json"
    )
    output_path.parent.mkdir(parents=True, exist_ok=True)
    with open(output_path, "w") as f:
        json.dump(dict, f, sort_keys=True, indent=4)
