import sys
from typing import *
from pathlib import Path

sys.path.append(str(Path(__file__).parent.resolve()))
sys.path.append(str(Path(__file__).parent.parent.resolve()))
from common.util import get_verif_list, get_src_list
from common.verif_status_register import load_status
from code_info_register import calc_src_code_info, calc_verif_code_info
from json_data import save_json


def generate_json_datas():
    load_status()
    for verif_path in get_verif_list():
        calc_verif_code_info(verif_path)
    for src_path in get_src_list():
        calc_src_code_info(src_path)
    save_json()
