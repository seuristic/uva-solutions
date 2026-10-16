#include <bits/stdc++.h>
using namespace std;

using ll = long long;

void solve() {
  int n, m, s;
  int dr[] = {-1, 0, 1, 0};
  int dc[] = {0, 1, 0, -1};
  string dir_str = "NLSO";

  while (cin >> n >> m >> s && (n || m || s)) {
    vector<string> grid(n);

    int r = 0, c = 0;
    int dir_ind = -1;
    for (int i = 0; i < n; ++i) {
      cin >> grid[i];
      for (int j = 0; j < m; ++j) {
        if (isalpha(grid[i][j])) {
          r = i, c = j;
          dir_ind = dir_str.find(grid[i][j]);
        }
      }
    }

    string inst;
    cin >> inst;

    int ans = 0;
    for (char ch : inst) {
      if (ch == 'F') {
        int nr = r + dr[dir_ind];
        int nc = c + dc[dir_ind];
        if (nr < 0 || nc < 0 || nr >= n || nc >= m || grid[nr][nc] == '#')
          continue;
        if (grid[nr][nc] == '*') {
          grid[nr][nc] = '.';
          ++ans;
        }
        r = nr, c = nc;
      } else {
        int val = (ch == 'D' ? 1 : -1);
        dir_ind = (4 + dir_ind + val) % 4;
      }
    }

    cout << ans << '\n';
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
