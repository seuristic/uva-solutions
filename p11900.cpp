#include <bits/stdc++.h>
using namespace std;

using ll = long long;

void solve() {
  int n, p, q;
  cin >> n >> p >> q;
  vector<int> a(n);
  for (int& x : a) cin >> x;

  int cnt = 0, sum = 0;
  for (int i = 0; i < n && cnt < p; ++i) {
    if (sum + a[i] <= q) {
      sum += a[i];
      ++cnt;
    }
  }

  cout << cnt << '\n';
}

int main() {
  ios::sync_with_stdio(false);
  cin.tie(nullptr);

  int tc = 1;
  cin >> tc;
  for (int t = 1; t <= tc; ++t) {
    cout << "Case " << t << ": ";
    solve();
  }

  return 0;
}
