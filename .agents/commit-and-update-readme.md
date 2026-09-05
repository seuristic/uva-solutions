# Commit & update README
Followed when the user asks any agent to commit or push in this repo.
Solutions live in `solutions/pNNNNN.cpp`; each has one row in the `README.md` table.

## When asked to commit / push

1. `git status --short --untracked-files=all` and `git diff` to see what changed.
2. For each **new** `solutions/pNNNNN.cpp`: read it, infer the algorithm/technique
   used, and append a row to the table in `README.md`:

   ```
   | [NNNNN](https://github.com/seuristic/uva-solutions/blob/main/solutions/pNNNNN.cpp) | <approach>              |
   ```

   - `NNNNN` is the filename digits verbatim (zero-padded, e.g. `01105`); the link
     text keeps that padding.
   - Rows are appended at the end — the table is not sorted.
   - Pad the approach cell with spaces so the trailing `|` lines up with the rows above.
   - `<approach>` is a short lowercase technique list, comma-separated:
     `greedy, sorting`, `2D prefix sum`, `binary search`.
   - Skip files that already have a row.
3. Stage everything and commit with a conventional commit message:
   - new solution(s): `feat: add solution for UVa NNNNN` (drop leading zeros here)
   - edits to existing solutions: `fix:` or `refactor:` as appropriate
   - README/structure only: `docs:` / `refactor:`
4. Push only if the user asked for it.

Non-solution files (`a.out`, `file.in`, `file.out`, `expected.out`) are scratch —
no README rows for them.
