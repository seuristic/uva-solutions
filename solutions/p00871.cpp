#include <bits/stdc++.h>
using namespace std;

using ll = long long;

int dr[] = {0, 1, 1, 1, 0, -1, -1, -1};
int dc[] = {-1, -1, 0, 1, 1, 1, 0, -1};

int n, m;
vector<string> grid;

int dfs(int r, int c) {
  grid[r][c] = '2';

  int count = 1;

  for (int i = 0; i < 8; ++i) {
    int nr = r + dr[i];
    int nc = c + dc[i];

    if (nr < 0 || nr >= n || nc < 0 || nc >= m || grid[nr][nc] != '1') continue;

    count += dfs(nr, nc);
  }

  return count;
}

int main() {
  ios::sync_with_stdio(false);
  cin.tie(nullptr);

  int tc = 1;
  cin >> tc;

  string line;

  getline(cin, line);
  getline(cin, line);

  while (tc--) {
    grid.clear();

    while (getline(cin, line) && !line.empty()) {
      grid.push_back(line);
    }

    n = int(grid.size());
    m = int(grid[0].size());

    int ans = 0;

    for (int r = 0; r < n; ++r) {
      for (int c = 0; c < m; ++c) {
        if (grid[r][c] == '1') {
          ans = max(ans, dfs(r, c));
        }
      }
    }

    cout << ans << '\n';
    if (tc > 0) cout << '\n';
  }

  return 0;
}
