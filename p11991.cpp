#include <bits/stdc++.h>
using namespace std;

constexpr int MAX = 1e6 + 5;

void solve() {
  int n, m;
  while (cin >> n >> m) {
    vector<int> a(n);
    vector<vector<int>> al(MAX);
    for (int i = 0; i < n; ++i) {
      int x;
      cin >> x;
      al[x].push_back(i + 1);
    }
    while (m--) {
      int x, y;
      cin >> x >> y;
      if (int(al[y].size()) >= x) {
        cout << al[y][x - 1] << endl;
      } else {
        cout << 0 << endl;
      }
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
