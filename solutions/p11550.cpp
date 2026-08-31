#include <bits/stdc++.h>
using namespace std;

void solve() {
  int n, m;
  cin >> n >> m;
  vector<vector<int>> am(n, vector<int>(m));
  vector<int> count_edge(m);
  for (int i = 0; i < n; ++i) {
    for (int j = 0; j < m; ++j) {
      cin >> am[i][j];
      if (am[i][j]) {
        ++count_edge[j];
      }
    }
  }

  for (int c : count_edge) {
    if (c != 2) {
      cout << "No" << endl;
      return;
    }
  }

  for (int i = 0; i < n - 1; ++i) {
    for (int j = i + 1; j < n; ++j) {
      int same_cols = 0;
      for (int k = 0; k < m; ++k) {
        if (am[i][k] && am[j][k]) {
          if (same_cols) {
            cout << "No" << endl;
            return;
          }
          ++same_cols;
        }
      }
    }
  }

  cout << "Yes" << endl;
}

int main() {
  ios::sync_with_stdio(false);
  cin.tie(nullptr);

  int tc = 1;
  cin >> tc;
  while (tc--) solve();

  return 0;
}
