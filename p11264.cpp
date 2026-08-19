#include <bits/stdc++.h>
using namespace std;

using ll = long long;

void solve() {
  int n;
  cin >> n;

  vector<ll> a(n);
  for (ll& x : a) cin >> x;

  if (n == 1) {
    cout << 1 << '\n';
    return;
  }

  ll sum = a[0];
  int ans = 2;

  for (int i = 1; i < n - 1; ++i) {
    if (sum + a[i] < a[i + 1]) {
      sum += a[i];
      ++ans;
    }
  }

  cout << ans << '\n';
}

int main() {
  ios::sync_with_stdio(false);
  cin.tie(nullptr);

  int tc = 1;
  cin >> tc;
  while (tc--) solve();

  return 0;
}
