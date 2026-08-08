#include <bits/stdc++.h>
using namespace std;

void solve() {
  int s, d;
  while (cin >> s >> d) {
    int ans = -1;
    for (int mask = 1; mask < (1 << 12); ++mask) {
      int net = 5 * s - (s + d) * __builtin_popcount(mask & 31);
      if (net >= 0) continue;
      bool ok = true;
      for (int i = 1; i < 8 && ok; ++i) {
        if (mask & (1 << (i - 1))) {
          net += d;
        } else {
          net -= s;
        }
        if (mask & (1 << (i + 4))) {
          net -= d;
        } else {
          net += s;
        }

        if (net >= 0) ok = false;
      }
      if (!ok) continue;
      int sum = s * 12 - (s + d) * __builtin_popcount(mask);
      ans = max(ans, sum);
    }
    if (ans == -1) cout << "Deficit\n";
    else cout << ans << '\n';
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
