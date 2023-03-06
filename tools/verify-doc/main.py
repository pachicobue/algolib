from typing import *
from argparse import ArgumentParser
from pathlib import Path
from logging import INFO, basicConfig, getLogger
from common.config import *
from common.verif_status_register import load_status, save_status
from common.util import get_verif_list
from verify.verify import check_verify_register
from doc.doc import generate_json_datas

_logger = getLogger(__name__)

if __name__ == "__main__":
    basicConfig(level=INFO, format="[%(levelname)s] %(message)s")
    parser = ArgumentParser(description="Test/Documentation tool")
    subparser = parser.add_subparsers(dest="subcommand")

    parser_verify = subparser.add_parser("run", help="Run verification")
    parser_verify.add_argument("--file", help="Test file (ignored by --all)")
    parser_verify.add_argument(
        "-a", "--all", action="store_true", help="Verify all tests"
    )
    parser_verify.add_argument("--tle", default=60.0, type=float)

    parser_verify = subparser.add_parser("doc", help="Generate json")

    args = parser.parse_args()
    if args.subcommand == "run":
        tle = args.tle
        load_status()
        try:
            if args.all:
                _logger.info("$ main.py run --all")
                for verif_path in get_verif_list():
                    check_verify_register(verif_path, tle)
            else:
                assert args.file != None
                verif_path = Path(args.file)
                _logger.info("$ main.py run --file={}".format(verif_path))
                check_verify_register(verif_path, tle)
        finally:
            save_status()
    elif args.subcommand == "doc":
        _logger.info("$ main.py doc")
        generate_json_datas()
    else:
        parser.print_help()
