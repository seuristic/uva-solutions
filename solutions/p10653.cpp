#include <bits/stdc++.h>
using namespace std;

using ll = long long;

int dir[] = {0, -1, 0, 1, 0};

void solve() {
  int n, m;
  while (cin >> n >> m && (n || m)) {
    vector<vector<bool>> bomb(n, vector<bool>(m, false));

    int rows;
    cin >> rows;

    while (rows--) {
      int row_id, bombs;
      cin >> row_id >> bombs;

      while (bombs--) {
        int col_id;
        cin >> col_id;
        bomb[row_id][col_id] = true;
      }
    }

    pair<int, int> src, dest;
    cin >> src.first >> src.second;
    cin >> dest.first >> dest.second;

    int ans = -1;
    queue<pair<int, int>> q;
    vector<vector<int>> dist(n, vector<int>(m, -1));

    q.push(src);
    dist[src.first][src.second] = 0;

    while (!q.empty()) {
      auto [r, c] = q.front();
      q.pop();

      if (make_pair(r, c) == dest) {
        ans = dist[r][c];
        break;
      }

      for (int i = 0; i < 4; ++i) {
        int nr = r + dir[i];
        int nc = c + dir[i + 1];

        if (nr < 0 || nr >= n || nc < 0 || nc >= m || bomb[nr][nc] ||
            dist[nr][nc] != -1)
          continue;

        dist[nr][nc] = dist[r][c] + 1;
        q.push({nr, nc});
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
