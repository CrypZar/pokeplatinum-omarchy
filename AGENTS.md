# Agent Instructions

This repository is a work-in-progress decompilation of Pokémon Platinum. The
long-term roadmap has two related but distinct outcomes:

1. finish the decompilation while preserving the reference ROM's behavior; and
2. establish a reproducible game development and runtime workflow on Omarchy
   Linux.

Read this file before making changes. The detailed orchestration workflow is in
[`docs/agents/orchestration.md`](docs/agents/orchestration.md), and the current
roadmap is in [`docs/roadmap.md`](docs/roadmap.md).

## Working rules

- Keep changes narrowly scoped to the assigned work item.
- Treat matching behavior as the source of truth for decompilation work.
- Do not replace unknown game logic with guesses. Record uncertainty and the
  evidence needed to resolve it.
- Preserve generated files and build conventions unless the task explicitly
  changes them.
- Do not commit proprietary ROMs, extracted copyrighted assets, credentials, or
  machine-local build output.
- Prefer existing project entry points such as `make check`, `make format`, and
  the Meson test suite.
- Update documentation when a discovery changes how another contributor can
  build, test, or understand the project.

## Before editing

1. Read the relevant roadmap and task brief.
2. Inspect the existing implementation and nearby documentation.
3. Establish a baseline with the smallest relevant build or test command.
4. State the files and behavior that are in scope.

## Before handoff

Run the applicable validation commands, record their results, and report:

- what changed;
- what was verified;
- what remains uncertain;
- which files or artifacts the next agent should inspect; and
- the next recommended task.

The handoff format is defined in
[`docs/agents/handoff-template.md`](docs/agents/handoff-template.md).

## Validation gates

For ordinary source changes, use at least:

```bash
make check
make format
```

Use narrower tests during iteration, but do not claim completion without the
appropriate project-wide checks. Linux-port work must also follow the matrix in
[`docs/agents/validation-matrix.md`](docs/agents/validation-matrix.md).

## Git and integration

- Use a focused branch and commits with descriptive messages.
- Avoid drive-by formatting or unrelated refactors.
- Do not rewrite another agent's work without recording the reason.
- The coordinator integrates work only after its validation evidence is
  available.

## Agent roles

The available roles and their boundaries are described in
[`docs/agents/roles.md`](docs/agents/roles.md). When a task could be handled by
multiple roles, the coordinator assigns one owner and names the reviewers.
