# Omarchy Linux Roadmap

This track establishes a supported workflow on Omarchy Linux. It must not
silently conflate building the Nintendo DS ROM with running a native Linux
program.

## First decision: define the runtime target

Before implementation begins, record which target is intended:

- development and ROM-building environment only;
- emulator-based game runtime;
- compatibility-layer runtime; or
- native reimplementation/runtime.

The choice affects graphics, audio, input, save handling, licensing, packaging,
and the definition of “port complete.” Record it in
[`../agents/decision-log.md`](../agents/decision-log.md).

## Workstreams

### Build environment

- Verify the Omarchy/Arch package names and supported versions.
- Install the ARM toolchain, Meson/Ninja, Python, image libraries, and project
  utilities required by `INSTALL.md`.
- Confirm `make configure` and `make check` from a clean checkout.
- Document environment variables and artifact locations.

### Development workflow

- Provide editor, debugger, logging, and clean-build instructions.
- Define release and debug build profiles.
- Document how agents capture logs and attach reproducible evidence.

### Runtime integration

After the runtime target is selected, define requirements for windowing,
graphics, audio, input, filesystem access, saves, and controller mapping.

### Packaging

- Define the launcher and executable layout.
- Define how required assets are supplied without committing restricted files.
- Add versioning, logs, and failure-reporting guidance.
- Decide whether packaging is a project artifact or a downstream distribution
  responsibility.

## Exit criteria

- A clean Omarchy installation can follow the documented setup.
- The repository builds from a clean checkout.
- The selected runtime reaches a defined smoke-test state.
- Input, audio/video, and save/load behavior pass the validation matrix.
- Known limitations and unsupported hardware are documented.
- No instruction depends on an agent's private machine state.
