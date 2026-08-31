#include <bits/stdc++.h>
using namespace std;

void solve() {
  int n, m;
  while (cin >> n >> m, n || m) {
    vector<int> reliable(n + 1), not_reliable(n + 1);
    while (m--) {
      int x, y;
      cin >> x >> y;
      if (y > 0) reliable[x - 1] |= 1 << (y - 1);
      else not_reliable[x - 1] |= 1 << (-y - 1);
    }

    int ans = 0;
    for (int mask = 1; mask < (1 << n); ++mask) {
      bool possible = true;
      for (int i = 0; i < n && possible; ++i) {
        if (mask & (1 << i)) {
          if ((reliable[i] & ~mask) || (not_reliable[i] & mask)) {
            possible = false;
          }
        }
      }
      if (possible) {
        ans = max(ans, __builtin_popcount(mask));
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
