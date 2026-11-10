# Multi-Agent Orchestration Workflow

This document defines how contributors and automated agents coordinate work on
the decompilation and the Omarchy Linux roadmap.

## Operating model

The coordinator turns roadmap outcomes into bounded work packages. Specialist
agents investigate or implement one package at a time, produce evidence, and
hand the result back for review. No agent should infer that an adjacent task is
also in scope.

```text
Coordinator
  -> reconnaissance and decomposition
  -> parallel specialist work
  -> evidence review
  -> implementation or integration
  -> build and regression validation
  -> documentation and handoff
```

Parallel work is appropriate only when agents do not edit the same files or
depend on unverified assumptions from one another. Shared architectural
decisions are resolved by the coordinator and recorded in
[`decision-log.md`](decision-log.md).

## Work-package contract

Every work package must state:

- objective and non-goals;
- owner role and reviewers;
- source files, generated files, and external inputs;
- dependencies and assumptions;
- expected code, data, or documentation artifacts;
- validation commands and expected results;
- risk of behavior, build, or portability regressions; and
- completion criteria.

Use [`task-template.md`](task-template.md) for new packages.

## Workflow stages

### 1. Reconnaissance

The coordinator identifies the current state, reads relevant project guidance,
checks the working tree, and runs a baseline command. The output is a short
task brief with explicit scope.

### 2. Decomposition

Break the outcome into independently verifiable packages. Examples include a
single unidentified function family, a build dependency, a Linux input issue,
or a missing regression test.

### 3. Investigation

Analyst agents gather evidence before proposing implementation. Evidence may
include matching results, disassembly, existing scripts, compiler output,
runtime logs, or a reproducible failure. Findings without a proposed code
change are still valuable and should be handed off.

### 4. Implementation

The assigned implementation agent makes the smallest change that satisfies the
package. It updates tests and documentation when the behavior or workflow has
changed.

### 5. Verification

The test/verification role runs the commands listed in the package and checks
that generated outputs are reproducible. Failures become new bounded packages;
they are not silently worked around.

### 6. Review and integration

The coordinator checks scope, evidence, documentation, and conflicts before
integrating. A package is complete only when its completion criteria and all
required validation gates pass.

### 7. Handoff

Use [`handoff-template.md`](handoff-template.md). A handoff must be useful to an
agent that has not seen the preceding conversation.

## Escalation rules

Escalate when:

- the task requires a choice not covered by the roadmap;
- behavior cannot be established from available evidence;
- two agents reach incompatible conclusions;
- a change would alter the runtime target or asset policy; or
- validation is blocked by missing tools, ROM inputs, or hardware.

Record the decision, alternatives, and evidence rather than resolving the
conflict implicitly.
