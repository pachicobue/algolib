from pathlib import Path
from typing import *

script_root_dir: Path = Path(__file__).parent
workspace_dir: Path = script_root_dir.parent.parent.resolve()
library_dir: Path = workspace_dir / "src"
verification_dir: Path = workspace_dir / "verifications"

compile_command: str = "g++"
include_directories: List[Path] = [library_dir]
defined_macro: List[str] = []
compile_flags: List[str] = ["-std=c++17", "-O2"]

for dir in include_directories:
    compile_flags += ["-I", str(dir)]
for macro in defined_macro:
    compile_flags += ["-D", macro]

verif_workspace: Path = workspace_dir / "tools/.workspace"
verif_workspace.mkdir(parents=True, exist_ok=True)

remote_json: Path = verif_workspace / "remote.json"
local_json: Path = verif_workspace / "local.json"
