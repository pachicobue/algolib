import sys
import json
from datetime import datetime, timezone, timedelta
from pathlib import Path

sys.path.append(str(Path(__file__).parent.resolve()))
from config import *
from util import get_json
from result import VerifResult

_error_timestamp: datetime = datetime.fromtimestamp(0, tz=timezone(timedelta()))


class VerifStatus:
    def __init__(self, verif_date: datetime, verif_result: VerifResult):
        self.date = verif_date
        self.result = verif_result


_verif_statuses: Dict[Path, VerifStatus] = {}


def clear_statuses() -> None:
    _verif_statuses = {}


def refer_status(verif_path: Path) -> VerifStatus:
    if verif_path in _verif_statuses:
        return _verif_statuses[verif_path]
    else:
        return VerifStatus(_error_timestamp, VerifResult.INVALID)


def load_status() -> None:
    clear_statuses()
    with open(get_json()) as fp:
        dict = json.load(fp)
        for path, status in dict.items():
            date: datetime = datetime.strptime(status["date"], "%Y-%m-%d %H:%M:%S %z")
            result: VerifResult = VerifResult(status["result"])
            _verif_statuses[verification_dir / path] = VerifStatus(date, result)


def mark_status(verif_path: Path, verif_status: VerifStatus) -> None:
    _verif_statuses[verif_path] = verif_status


def save_status() -> None:
    dict = {}
    for path, status in _verif_statuses.items():
        subdict = {}
        subdict["date"] = status.date.strftime("%Y-%m-%d %H:%M:%S %z")
        subdict["result"] = status.result.value
        dict[str(path.relative_to(verification_dir))] = subdict
    with open(get_json(), "w") as fp:
        json.dump(dict, fp, sort_keys=True, indent=4)
