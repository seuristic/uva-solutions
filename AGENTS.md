# uva-solutions — agent instructions

Repo of UVa Online Judge solutions. Every solution lives in `solutions/pNNNNN.cpp`
and has one row in the `README.md` table.

## When asked to commit / push

1. `git status --short --untracked-files=all` and `git diff` to see what changed.
2. For each **new** `solutions/pNNNNN.cpp`: read it, infer the algorithm/technique
   used, and append a row to the table in `README.md`:

   ```
   | [NNNNN](https://github.com/seuristic/uva-solutions/blob/main/solutions/pNNNNN.cpp) | <approach> |
   ```

   - `NNNNN` is the filename digits verbatim (zero-padded, e.g. `01105`); the link
     text keeps that padding.
   - Rows are appended at the end — the table is not sorted.
   - `<approach>` is a short lowercase technique list, comma-separated:
     `greedy, sorting`, `2D prefix sum`, `binary search`.
   - Skip files that already have a row.

3. Format the table: `npx --yes prettier --write README.md`
   (this is what keeps the column padding aligned — don't hand-pad).
4. Stage everything and commit with a conventional commit message:
   - new solution(s): `feat: add solution for UVa NNNNN` (drop leading zeros here)
   - edits to existing solutions: `fix:` or `refactor:` as appropriate
   - README/structure only: `docs:` / `refactor:`
5. Push only if the user asked for it.

Non-solution files (`a.out`, `file.in`, `file.out`, `expected.out`) are scratch —
no README rows for them.
