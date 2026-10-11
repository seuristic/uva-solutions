#include <bits/stdc++.h>
using namespace std;

using ll = long long;

enum { UNVISITED = -1, VISITED = -2 };

int n, m, start, dfs_cnt, cycle_start, cycle_len, total_steps;
vector<string> grid;
vector<vector<int>> dfs_num;

void dfs(int r, int c) {
  dfs_num[r][c] = ++dfs_cnt;

  int nr = r, nc = c;
  switch (grid[r][c]) {
    case 'N': --nr; break;
    case 'S': ++nr; break;
    case 'W': --nc; break;
    default: ++nc;
  }

  if (nr < 0 || nr >= n || nc < 0 || nc >= m) {
    total_steps = dfs_cnt;
  } else if (dfs_num[nr][nc] == UNVISITED) {
    dfs(nr, nc);
  } else {
    cycle_start = dfs_num[nr][nc] - 1;
    cycle_len = dfs_cnt - cycle_start;
  }
}

void solve() {
  while (cin >> n >> m >> start && (n || m || start)) {
    grid.assign(n, "");
    dfs_cnt = 0;
    dfs_num.assign(n, vector<int>(m, UNVISITED));
    total_steps = -1;

    for (int i = 0; i < n; ++i) {
      cin >> grid[i];
    }

    dfs(0, start - 1);

    if (total_steps == -1) {
      cout << cycle_start << " step(s) before a loop of " << cycle_len
           << " step(s)\n";
    } else {
      cout << total_steps << " step(s) to exit\n";
    }
  }
}

int main() {
  ios::sync_with_stdio(false);
  cin.tie(nullptr);

  int tc = 1;
  // cin >> tc;
  while (tc--) solve();

  return 0;
}
