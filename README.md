# Pokémon Platinum: Omarchy Edition

This is a work-in-progress decompilation of Pokémon Platinum — the foundation
for building the ultimate version of Sinnoh's definitive adventure. Our goal is
to preserve the original game faithfully, make every system understandable and
maintainable, and create a modern, reproducible development and runtime
experience for contributors and players.

The project is being developed in deliberate stages: first understand and
rebuild the original game, then improve the tooling and platform experience,
and finally add carefully designed enhancements without losing what makes
Pokémon Platinum special.

For setup instructions, see [`INSTALL.md`](INSTALL.md). Contributors and agents
should read [`CONTRIBUTING.md`](CONTRIBUTING.md) and [`AGENTS.md`](AGENTS.md).

## 🧭 The roadmap

The roadmap is organized around one principle:

> **Build the most faithful, moddable, testable, accessible, and enjoyable
> Pokémon Platinum experience possible.**

That means “ultimate” is not just a list of new features. It means a strong
technical foundation, measurable compatibility, excellent tools, and a clear
separation between preservation work and optional enhancements.

### Phase 1 — Finish the decompilation 🧩

Complete the reconstruction of the original Pokémon Platinum codebase while
maintaining matching behavior and reproducible builds.

- Identify and document remaining functions, symbols, structures, scripts,
  overlays, constants, and data formats.
- Replace unknown or opaque code with clear, idiomatic C and assembly while
  preserving the original ABI and behavior.
- Improve naming, comments, subsystem boundaries, and source-level navigation.
- Document maps, scripts, messages, trainers, items, moves, Pokémon data,
  graphics, sound, and generated files.
- Make generated data and build artifacts reproducible from a clean checkout.
- Expand regression coverage for gameplay systems and fragile engine behavior.
- Track matching status with evidence instead of relying on subjective
  completion percentages.

**Exit goal:** a clean checkout can build the intended ROM, pass the project
test suite, and explain the remaining source and data coverage.

### Phase 2 — Build a world-class development toolkit 🛠️

Turn the decompilation into a project that is welcoming to researchers,
modders, artists, testers, and future maintainers.

- Make setup reliable on supported Linux environments.
- Improve build diagnostics, logging, debug builds, and incremental builds.
- Add scripts and documentation for inspecting ROM data and generated files.
- Provide repeatable workflows for exploring maps, scripts, battle systems,
  rendering, audio, saves, and networking-related interfaces.
- Keep source, generated data, tools, and build output clearly separated.
- Make common tasks discoverable through `make`, Meson, and documented helper
  commands.
- Use continuous integration to catch build, formatting, and regression issues.

**Exit goal:** a new contributor can go from clone to a verified build with
minimal undocumented tribal knowledge.

### Phase 3 — Omarchy Linux workflow 🐧

Make Omarchy Linux a first-class environment for building, testing, and using
the project. The exact runtime strategy will be recorded before platform work
begins; building the Nintendo DS ROM and running a Linux program are separate
technical goals.

- Verify Arch/Omarchy package names, versions, and toolchain requirements.
- Provide clean-checkout setup instructions and reproducible dependency lists.
- Support release and debug workflows with useful logs and artifacts.
- Define the target runtime: ROM-building environment, emulator workflow,
  compatibility layer, or a native runtime.
- Establish reliable windowing, graphics, audio, input, controller, filesystem,
  and save-data behavior for the selected target.
- Add smoke tests for launch, rendering, audio, input, persistence, and a
  representative gameplay path.
- Document packaging, launching, troubleshooting, and known hardware limits.

**Exit goal:** an Omarchy user can install the documented dependencies, build
from a clean checkout, launch the selected target, and reproduce the validation
results.

### Phase 4 — The ultimate Platinum foundation ✨

Once the original game is understood and the platform workflow is reliable,
build the foundation for optional improvements while keeping the original game
available as a stable reference.

- Establish a clean configuration system for optional features.
- Keep original behavior selectable and regression-tested.
- Make data-driven changes possible without unnecessary code forks.
- Improve accessibility and quality-of-life options where they can be added
  without obscuring the original experience.
- Improve resolution, display scaling, input mapping, save management, and
  developer diagnostics where the selected runtime supports them.
- Create safe extension points for new maps, encounters, events, scripts,
  trainers, items, moves, graphics, and audio.
- Provide clear compatibility labels so users know whether they are playing
  the original experience or an enhanced configuration.

**Exit goal:** enhancements are modular, documented, testable, and reversible;
the preserved original remains the reference point.

### Phase 5 — Optional enhancements and community edition 🌟

Explore improvements that make the game feel like the definitive Sinnoh
experience, subject to design review, technical feasibility, and project scope.

Possible areas include:

- quality-of-life improvements that respect the original game loop;
- expanded configuration and accessibility options;
- improved interface clarity and usability;
- additional challenge, randomization, or replayability modes;
- curated new content built with the documented data and scripting tools;
- modern debugging, modding, and content-authoring workflows;
- community-maintained compatibility packs and balanced rule sets.

Every enhancement should answer three questions:

1. Can it be enabled or disabled cleanly?
2. Can it be tested and reproduced?
3. Does it preserve a clear path to the original Pokémon Platinum experience?

## ✅ Definition of done

The project is successful when it provides:

- **Fidelity:** the original game can be rebuilt and verified.
- **Understanding:** major code, data, and engine systems are documented.
- **Reproducibility:** builds and generated artifacts do not depend on one
  developer's private machine.
- **Moddability:** contributors can change content through stable, documented
  tools and data formats.
- **Portability:** the supported Omarchy Linux workflow is clean and tested.
- **Quality:** changes are protected by formatting, build, and regression
  checks.
- **Choice:** players can distinguish the preserved experience from optional
  enhancements.
- **Longevity:** future contributors can understand why decisions were made and
  continue the work without reverse-engineering the process again.

## 🤝 How work is coordinated

Large goals are divided into bounded work packages. Specialist contributors or
agents investigate one area, produce evidence, run the relevant checks, and
hand the result back for integration. The workflow, roles, task templates, and
validation gates are documented in
[`docs/agents/orchestration.md`](docs/agents/orchestration.md).

Track-specific details live in:

- [Project roadmap](docs/roadmap.md)
- [Decompilation roadmap](docs/roadmap/decompilation.md)
- [Omarchy Linux roadmap](docs/roadmap/omarchy-linux.md)
- [Agent roles](docs/agents/roles.md)
- [Validation matrix](docs/agents/validation-matrix.md)

## 🚧 Current status

The repository is currently focused on the decompilation and the foundations
needed for a reliable multi-agent development workflow. The Omarchy runtime
target and any post-decompilation enhancement set remain explicit roadmap
decisions, not assumptions hidden inside the build system.

Progress should be measured by working code, matching results, passing tests,
reproducible commands, and useful documentation.

This repository builds the following ROMs:

* [**pokeplatinum.us.nds**](https://datomatic.no-intro.org/index.php?page=show_record&s=28&n=4997) (Rev 1): `sha1: 0862ec35b24de5c7e2dcb88c9eea0873110d755c`
* [**pokeplatinum.us.nds**](https://datomatic.no-intro.org/index.php?page=show_record&s=28&n=3541) (Rev 0): `sha1: ce81046eda7d232513069519cb2085349896dec7`

For contacts and other pret projects, see [pret.github.io](https://pret.github.io/).
