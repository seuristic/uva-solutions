#include <bits/stdc++.h>
using namespace std;

void solve(int tid) {
  int n;
  cin >> n;
  int cnt = 0;
  while (n & (n + 1)) {
    int msb = 31 - __builtin_clz(n);
    n = n ^ (1 << msb);
    n = (n << 1) + 1;
    ++cnt;
  }
  cout << "Case " << tid << ": " << cnt << ' ' << n << '\n';
}

int main() {
  ios::sync_with_stdio(false);
  cin.tie(nullptr);

  int tc = 1;
  cin >> tc;
  for (int t = 1; t <= tc; ++t) solve(t);

  return 0;
}
