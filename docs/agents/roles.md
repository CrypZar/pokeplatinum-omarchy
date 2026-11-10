# Agent Roles

Roles describe responsibilities, not separate people. One contributor may fill
several roles, but each work package should have one accountable owner.

## Coordinator

Owns roadmap state, task decomposition, dependencies, conflict resolution, and
integration. Does not approve work without validation evidence.

## Decompilation analyst

Investigates unknown functions, symbols, data structures, scripts, overlays, and
matching behavior. Produces evidence and minimal patches. Does not redesign
game logic to make it cleaner.

## Assembly and compiler specialist

Investigates ABI details, compiler behavior, linker output, assembly matching,
and generated artifacts. Documents toolchain assumptions and reproducibility.

## Data and asset specialist

Documents maps, messages, graphics, scripts, constants, and generated data.
Keeps source-of-truth relationships clear and avoids committing restricted
source material.

## Build and tooling specialist

Maintains Make, Meson, MetroSkrew, helper scripts, CI, and developer setup.
Verifies clean builds and avoids environment-specific workarounds.

## Linux port specialist

Owns the Omarchy Linux development and runtime work after the runtime target is
explicitly selected. Covers dependencies, windowing, input, audio, graphics,
files, packaging, and logs.

## Test and verification specialist

Defines regression checks, runs `make check`, compares expected artifacts, and
maintains the validation matrix. Reports failures with exact reproduction steps.

## Documentation maintainer

Turns discoveries into durable, navigable Markdown. Removes duplication,
keeps links valid, and ensures instructions match verified commands.
