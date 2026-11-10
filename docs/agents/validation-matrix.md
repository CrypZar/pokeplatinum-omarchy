# Validation Matrix

Use the smallest applicable checks during development, then run the milestone
checks before integration.

| Area | Check | Expected result |
| --- | --- | --- |
| Formatting | `make format` | No formatting changes remain |
| Decompilation build | `make check` | Build and Meson tests pass |
| Debug build | `make debug` | Debug artifacts build successfully |
| Clean setup | `make distclean && make check` | A fresh build succeeds |
| Documentation | Markdown link and heading review | Links and commands are valid |
| Linux dependencies | Clean Omarchy setup procedure | Required tools install without undocumented steps |
| Linux runtime | Port smoke test | Program launches and reaches the defined test state |
| Input | Controller/keyboard test | Required inputs are recognized |
| Audio/video | Rendering and audio smoke test | Output is present and stable |
| Persistence | Save/load test | Save data survives restart |
| Regression | Representative gameplay path | No known decompilation or port regression |

The Linux rows remain provisional until the runtime strategy is recorded in
[`docs/roadmap/omarchy-linux.md`](../roadmap/omarchy-linux.md).
