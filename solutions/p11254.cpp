#include <bits/stdc++.h>
using namespace std;

void solve() {
  long long x;
  while (cin >> x, x != -1) {
    long long ans_l = x, ans_r = x;
    long long two = x * 2;
    for (long long f = 2; f * f <= two; ++f) {
      if (two % f != 0) continue;
      long long a = f;
      long long b = two / f;
      if ((a ^ b) & 1) continue;
      long long n = (a + b - 1) / 2, m = (b - a - 1) / 2;
      if (ans_r - ans_l + 1 < n - m) {
        ans_l = m + 1, ans_r = n;
      }
    }

    cout << x << " = " << ans_l << " + ... + " << ans_r << '\n';
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
