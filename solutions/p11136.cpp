#include <bits/stdc++.h>
using namespace std;

void solve() {
  int n;
  while (cin >> n && n > 0) {
    multiset<long long> urn;
    long long ans = 0;
    for (int i = 0; i < n; ++i) {
      int k;
      cin >> k;
      for (int j = 0; j < k; ++j) {
        long long b;
        cin >> b;
        urn.insert(b);
      }
      auto it = urn.end();
      --it;
      ans += *it - *urn.begin();
      urn.erase(it);
      urn.erase(urn.begin());
    }
    cout << ans << endl;
  }
}

int main() {
  cin.tie(nullptr)->sync_with_stdio(false);
  int tc = 1;
  // cin >> tc;
  while (tc--) solve();
}
