#include <bits/stdc++.h>
using namespace std;

using ll = long long;

int dir[] = {0, -1, 0, 1, 0};

void solve() {
  int n, m;
  while (cin >> n >> m && (n || m)) {
    vector<vector<bool>> bomb_area(n, vector<bool>(m, false));

    int rows;
    cin >> rows;

    while (rows--) {
      int row_id, bombs;
      cin >> row_id >> bombs;

      while (bombs--) {
        int col_id;
        cin >> col_id;
        bomb_area[row_id][col_id] = true;
      }
    }

    pair<int, int> src, dest;
    cin >> src.first >> src.second;
    cin >> dest.first >> dest.second;

    int time_taken = 0;
    queue<pair<int, int>> q;

    q.push(src);
    bomb_area[src.first][src.second] = false;

    while (!q.empty()) {
      int qsize = q.size();
      bool found = false;

      while (qsize--) {
        auto [r, c] = q.front();
        q.pop();

        for (int i = 0; i < 4; ++i) {
          int nr = r + dir[i];
          int nc = c + dir[i + 1];

          if (nr < 0 || nr >= n || nc < 0 || nc >= m || bomb_area[nr][nc])
            continue;

          if (nr == dest.first && nc == dest.second) {
            found = true;
            break;
          }

          q.push({nr, nc});
          bomb_area[nr][nc] = true;
        }

        if (found) break;
      }

      ++time_taken;

      if (found) break;
    }

    cout << time_taken << '\n';
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
