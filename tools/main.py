from typing import *
from argparse import ArgumentParser
from pathlib import Path
from common.config import *
from common.status_register import load_status, save_status
from verify.verify import check_verify_register, get_verif_list


if __name__ == "__main__":
    parser = ArgumentParser(description="Test verification code")
    subparser = parser.add_subparsers(dest="subcommand")

    parser_verify = subparser.add_parser("run", help="Test verification file.")
    parser_verify.add_argument(
        "--file", help="Verification target (Only available on single test)"
    )
    parser_verify.add_argument(
        "-a", "--all", action="store_true", help="Verify all test file"
    )
    parser_verify.add_argument("--tle", default=60.0, type=float)

    args = parser.parse_args()
    if args.subcommand == "run":
        tle = args.tle
        load_status()
        try:
            if args.all:
                for verif_path in get_verif_list():
                    check_verify_register(
                        (verification_dir / verif_path).resolve(), tle
                    )
            else:
                assert args.file != None
                verif_path = Path(args.file).resolve()
                check_verify_register(verif_path, tle)
        finally:
            save_status()
    elif args.subcommand == "all":
        verif_path = Path(args.verif_path).resolve()
        tle = args.tle
        load_status()
        check_verify_register(verif_path, tle)
        save_status()
    else:
        parser.print_help()
