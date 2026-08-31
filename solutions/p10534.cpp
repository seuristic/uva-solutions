// #pragma GCC diagnostic ignored "-Wunused-but-set-variable"

#include <bits/stdc++.h>
using namespace std;

using ll = long long;

void solve() {
  int n;
  while (cin >> n) {
    vector<int> a(n);
    for (int i = 0; i < n; ++i) cin >> a[i];

    int k = 0;
    vector<int> lis(n);
    vector<int> lis_sz(n);
    for (int i = 0; i < n; ++i) {
      int pos = lower_bound(lis.begin(), lis.begin() + k, a[i]) - lis.begin();
      lis[pos] = a[i];
      lis_sz[i] = pos + 1;
      if (pos == k) ++k;
    }

    int ans = 1;

    int k2 = 0;
    vector<int> lis2(n);
    vector<int> lis_sz2(n);
    for (int i = n - 1; i >= 0; --i) {
      int pos =
          lower_bound(lis2.begin(), lis2.begin() + k2, a[i]) - lis2.begin();
      lis2[pos] = a[i];
      ans = max(ans, 2 * min(lis_sz[i], pos + 1) - 1);
      if (pos == k2) ++k2;
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
