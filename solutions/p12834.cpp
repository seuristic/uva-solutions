#include <bits/stdc++.h>
using namespace std;

using ll = long long;

void solve() {
  int n, k;
  cin >> n >> k;
  vector<pair<ll, ll>> xy(n);
  for (int i = 0; i < n; ++i) cin >> xy[i].first;
  for (int i = 0; i < n; ++i) cin >> xy[i].second;

  sort(xy.begin(), xy.end(), [](pair<ll, ll>& p1, pair<ll, ll>& p2) {
    ll d1 = p1.second - p1.first;
    ll d2 = p2.second - p2.first;
    return d1 > d2;
  });

  ll res = 0;
  for (int i = 0; i < n - k; ++i) {
    res += xy[i].second - xy[i].first;
  }

  for (int i = n - k; i < n; ++i) {
    res = max(res, res + xy[i].second - xy[i].first);
  }

  if (res <= 0) cout << "No Profit\n";
  else cout << res << '\n';
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
