from pathlib import Path
from typing import *

_this_script_dir: Path = Path(__file__).parent

#################################################################

library_root_dir: Path = _this_script_dir.parent.parent.parent.resolve(strict=True)
source_dir: Path = library_root_dir / "src"
verification_dir: Path = library_root_dir / "verifications"

#################################################################

compile_command: str = "g++"
include_directories: List[Path] = [source_dir]
defined_macro: List[str] = []
compile_flags: List[str] = ["-std=c++20", "-O2"]

for dir in include_directories:
    compile_flags += ["-I", str(dir)]
for macro in defined_macro:
    compile_flags += ["-D", macro]

###################################################################

workspace_dir: Path = library_root_dir / "tools/verify-doc/.workspace"

verify_workspace_dir: Path = workspace_dir / "verify"
verify_remote_json: Path = verify_workspace_dir / "remote.json"
verify_local_json: Path = verify_workspace_dir / "local.json"

doc_workspace_dir: Path = workspace_dir / "doc"
doc_data_dir: Path = doc_workspace_dir / "data"
src_data_json: Path = doc_data_dir / "src_stats.json"
verif_data_json: Path = doc_data_dir / "verif_stats.json"

###################################################################

exclude_src_paths: List[Path] = [
    source_dir / "internal/print/impl/",
    source_dir / "internal/print/prototype/",
    source_dir / "header.hpp.gch",
]
