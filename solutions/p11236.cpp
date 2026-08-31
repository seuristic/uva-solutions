#include <bits/stdc++.h>
using namespace std;

void solve() {
  for (int a = 1; a <= 500; ++a) {
    for (int b = a; b <= (2000 - a) / 3; ++b) {
      for (int c = b; c <= (2000 - a - b) / 2; ++c) {
        long long num = 1000000L * (a + b + c);
        long long den = 1LL * a * b * c - 1000000L;

        if (den <= 0 || num % den > 0) continue;

        int d = num / den;

        if (d < c || a + b + c + d > 2000) continue;

        cout << fixed << setprecision(2) << a / 100.0 << ' ' << b / 100.0 << ' '
             << c / 100.0 << ' ' << d / 100.0 << '\n';
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
