# watch-chain-wallet-mark

`watch-chain-wallet-mark` is a C project in blockchain tooling. Its focus is to implement a C blockchain tooling project for wallet incremental indexing, using append-only fixtures and checkpoint recovery checks.

## Project Rationale

I want this repository to be useful as a quick reading exercise: fixtures first, implementation second, verifier last.

## Watch Chain Wallet Mark Review Notes

For a quick review, compare `nonce pressure` with `event finality` before reading the middle cases.

## Feature Set

- `fixtures/domain_review.csv` adds cases for event finality and nonce pressure.
- `metadata/domain-review.json` records the same cases in structured form.
- `config/review-profile.json` captures the read order and the two review questions.
- `examples/watch-chain-wallet-walkthrough.md` walks through the case spread.
- The C code includes a review path for `nonce pressure` and `event finality`.
- `docs/field-notes.md` explains the strongest and weakest cases.

## Architecture

The core code exposes a scoring path and the added review layer uses `signal`, `slack`, `drag`, and `confidence`. The domain terms are `event finality`, `nonce pressure`, `settlement risk`, and `proof depth`.

The C code keeps the review rule close to the tests.

## Usage

```powershell
powershell -NoProfile -ExecutionPolicy Bypass -File scripts/verify.ps1
```

## Test Command

That command is also the regression path. It verifies the domain cases and catches mismatches between the CSV, metadata, and code.

## Next Improvements

No external service is required. A deeper version would add more negative cases and a clearer boundary around invalid input.
