# Decompilation Roadmap

The decompilation track is complete when the project can produce the intended
matching ROM from a clean checkout and the remaining source, data, and tooling
coverage is documented.

## Workstreams

| Workstream | What to measure | Completion evidence |
| --- | --- | --- |
| C and assembly | Matching and non-matching functions | Build comparison and tracked symbol status |
| Symbols and data | Unknown symbols, constants, structures | Source references and documented names |
| Scripts and overlays | Unidentified behavior and files | Reproducible extraction/build results |
| Generated data | Source-to-build transformations | Clean generation with no unexplained edits |
| Tooling | Build, analysis, and debugging gaps | Verified commands and documented dependencies |
| Tests | Coverage of changed behavior | Passing regression and Meson tests |

## Agent workflow

1. Select a bounded function, file family, or tool gap.
2. Establish a matching or build baseline.
3. Record evidence before changing behavior.
4. Implement the smallest change.
5. Run the relevant checks and update documentation.
6. Hand off using the standard template.

## Completion criteria

- A clean checkout builds successfully with the documented toolchain.
- `make check` passes.
- Remaining non-matching or unknown areas have an explicit disposition.
- Generated files are reproducible.
- The project documents how matching status is measured.
- No decompilation claim depends on an unrecorded local artifact.
