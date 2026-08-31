#include <bits/stdc++.h>
using namespace std;

using ll = long long;

const int dir[] = {0, -1, 0, 1, 0};

void solve() {
  int n;
  cin >> n;
  vector<string> grid(n);
  for (string& row : grid) cin >> row;

  for (int i = 0; i < n; ++i) {
    for (int j = 0; j < n; ++j) {
      if (grid[i][j] == '.') {
        unordered_set<char> uniq;
        for (int d = 0; d < 4; ++d) {
          int new_i = i + dir[d];
          int new_j = j + dir[d + 1];
          if (new_i >= 0 && new_i < n && new_j >= 0 && new_j < n &&
              grid[new_i][new_j] != '.') {
            uniq.insert(grid[new_i][new_j]);
          }
        }

        for (char c = 'A'; c <= 'Z'; ++c) {
          if (!uniq.count(c)) {
            grid[i][j] = c;
            break;
          }
        }
      }
    }
    cout << grid[i] << '\n';
  }
}

int main() {
  ios::sync_with_stdio(false);
  cin.tie(nullptr);

  int tc = 1;
  cin >> tc;
  for (int t = 1; t <= tc; ++t) {
    cout << "Case " << t << ":\n";
    solve();
  }

  return 0;
}
