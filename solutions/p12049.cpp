#include <bits/stdc++.h>
using namespace std;

void solve() {
  int n, m;
  cin >> n >> m;
  unordered_map<int, int> freq_a, freq_b;
  for (int i = 0; i < n; ++i) {
    int x;
    cin >> x;
    ++freq_a[x];
  }
  for (int i = 0; i < m; ++i) {
    int y;
    cin >> y;
    ++freq_b[y];
  }

  int ans = 0;
  unordered_set<int> taken;
  for (auto& [x, f1] : freq_a) {
    if (!freq_b.count(x) || freq_b[x] != f1) {
      ans += abs(f1 - freq_b[x]);
      taken.insert(x);
    }
  }

  for (auto& [y, f2] : freq_b) {
    if (taken.count(y)) continue;
    if (!freq_a.count(y) || freq_a[y] != f2) {
      ans += abs(f2 - freq_a[y]);
    }
  }

  cout << ans << endl;
}

int main() {
  cin.tie(nullptr)->sync_with_stdio(false);
  int tc = 1;
  cin >> tc;
  while (tc--) solve();
}
