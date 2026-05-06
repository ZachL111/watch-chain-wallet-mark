# Watch Chain Wallet Mark Walkthrough

I use this file as a small checklist before changing the C implementation.

| Case | Focus | Score | Lane |
| --- | --- | ---: | --- |
| baseline | event finality | 158 | ship |
| stress | nonce pressure | 239 | ship |
| edge | settlement risk | 168 | ship |
| recovery | proof depth | 168 | ship |
| stale | event finality | 226 | ship |

Start with `stress` and `baseline`. They create the widest contrast in this repository's fixture set, which makes them better review anchors than the middle cases.

The useful comparison is `nonce pressure` against `event finality`, not the raw score alone.
