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


def verify(all: bool, tle: float) -> None:
    load_status()
    try:
        if all:
            _logger.info("$ main.py verify --all")
            for verif_path in get_verif_list():
                check_verify_register(verif_path, tle)
        else:
            assert args.file != None
            verif_path = Path(args.file)
            _logger.info("$ main.py verify --file={}".format(verif_path))
            check_verify_register(verif_path, tle)
    finally:
        save_status()


def doc() -> None:
    _logger.info("$ main.py doc")
    generate_json_datas()


def publish() -> None:
    doc_data_dir.rename(library_root_dir / "data")


if __name__ == "__main__":
    basicConfig(level=INFO, format="[%(levelname)s] %(message)s")
    parser = ArgumentParser(description="Test/Documentation tool")
    subparser = parser.add_subparsers(dest="subcommand")

    parser_verify = subparser.add_parser("verify", help="Run verification")
    parser_verify.add_argument("--file", help="Test file (ignored by --all)")
    parser_verify.add_argument(
        "-a", "--all", action="store_true", help="Verify all tests"
    )
    parser_verify.add_argument("--tle", default=60.0, type=float)

    parser_doc = subparser.add_parser("doc", help="Generate json")
    parser_doc.add_argument(
        "--publish", help="Publish data/ folder", action="store_true"
    )

    args = parser.parse_args()
    if args.subcommand == "verify":
        verify(args.all, args.tle)
    elif args.subcommand == "doc":
        doc()
        if args.publish:
            publish()
    else:
        parser.print_help()
