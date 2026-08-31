#include <bits/stdc++.h>
using namespace std;

vector<vector<int>> possible;
vector<bool> rw, ld, rd;

void backtrack(int c, vector<int>& row) {
  if (c == 8) {
    possible.push_back(row);
    return;
  }

  for (int r = 0; r < 8; ++r) {
    if (rw[r] || ld[r + c] || rd[r - c + 7]) continue;
    rw[r] = ld[r + c] = rd[r - c + 7] = true;
    row.push_back(r);
    backtrack(c + 1, row);
    row.pop_back();
    rw[r] = ld[r + c] = rd[r - c + 7] = false;
  }
}

void precompute() {
  rw.assign(8, false);
  ld.assign(15, false);
  rd.assign(15, false);
  vector<int> row;
  backtrack(0, row);
  sort(possible.begin(), possible.end());
}

void solve() {
  int r, c;
  cin >> r >> c;
  vector<vector<int>> res;
  for (const auto& sol : possible) {
    if (sol[c - 1] == r - 1) {
      res.push_back(sol);
    }
  }

  cout << "SOLN       COLUMN\n";
  cout << " #      1 2 3 4 5 6 7 8\n\n";

  for (int i = 0; i < (int)res.size(); ++i) {
    cout << setw(2) << i + 1 << "      ";
    for (int j = 0; j < 8; ++j) {
      if (j) cout << ' ';
      cout << res[i][j] + 1;
    }
    cout << '\n';
  }
}

int main() {
  ios::sync_with_stdio(false);
  cin.tie(nullptr);

  precompute();

  int tc = 1;
  cin >> tc;
  bool first = true;
  while (tc--) {
    if (!first) cout << '\n';
    else first = false;
    solve();
  }

  return 0;
}
