# watch-chain-wallet-mark

`watch-chain-wallet-mark` treats blockchain tooling as a local verification problem. The C implementation is intentionally narrow, but the fixtures and notes make the behavior explicit.

## Watch Chain Wallet Mark Checkpoints

Treat the compact fixture as the contract and the extended examples as a scratchpad. The code should stay boring enough that a change in behavior is obvious from the test output.

## Architecture Notes

The design is intentionally direct: parse or construct a signal, score it, classify it, and verify the expected branch. This makes the repository useful for studying blockchain tooling behavior without needing a service or database unless the language project itself is SQL. The C implementation keeps headers, source, and assertions separate so bounds and types are easy to review.

## What This Is For

The repository exists to keep a technical idea small enough to reason about. The implementation avoids external dependencies where possible, then uses fixtures to make changes easy to review.

## Useful Pieces

- Uses fixture data to keep event replay changes visible in code review.
- Includes extended examples for invariant checks, including `recovery` and `degraded`.
- Documents settlement rules tradeoffs in `docs/operations.md`.
- Runs locally with a single verification command and no external credentials.
- Stores project constants and verification metadata in `metadata/project.json`.

## Case Study

`examples/extended_cases.csv` adds six named cases. I kept the names plain so failures are easy to read in a terminal: baseline, pressure, surge, degraded, recovery, and boundary.

## Project Layout

- `src`: primary implementation
- `tests`: verification harness
- `fixtures`: compact golden scenarios
- `examples`: expanded scenario set
- `metadata`: project constants and verification metadata
- `docs`: operations and extension notes
- `scripts`: local verification and audit commands

## Tooling

The only required setup is the local C toolchain. After cloning, stay in the repo root so fixture paths resolve correctly.

## Local Workflow

```powershell
powershell -NoProfile -ExecutionPolicy Bypass -File scripts/verify.ps1
```

This runs the language-level build or test path against the compact fixture set.

## Quality Gate

```powershell
powershell -NoProfile -ExecutionPolicy Bypass -File scripts/audit.ps1
```

The audit command checks repository structure and README constraints before it delegates to the verifier.

## Scope

The fixture set is deliberately small. That keeps the review surface clear, but it also means the model should not be treated as a complete domain simulator.

## Expansion Ideas

- Add a short report command that prints the score breakdown for a single scenario.
- Add malformed input fixtures so the failure path is as visible as the happy path.
- Split the scoring constants into a typed configuration object and validate it before use.
- Add one more blockchain tooling fixture that focuses on a malformed or borderline input.
