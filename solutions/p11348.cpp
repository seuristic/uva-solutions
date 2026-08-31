#include <bits/stdc++.h>
using namespace std;

void solve() {
  int n;
  cin >> n;
  unordered_map<int, int> stamp_user, stamp_freq;
  for (int i = 0; i < n; ++i) {
    int m;
    cin >> m;
    for (int j = 0; j < m; ++j) {
      int sid;
      cin >> sid;
      if (!stamp_user.count(sid) || stamp_user[sid] != i) {
        ++stamp_freq[sid];
      }
      stamp_user[sid] = i;
    }
  }

  vector<int> d(n);
  for (auto& [sid, count] : stamp_freq) {
    if (count == 1) ++d[stamp_user[sid]];
  }

  int total = accumulate(d.begin(), d.end(), 0);
  for (int i = 0; i < int(d.size()); ++i) {
    double ans = (total == 0) ? 0.0 : (100.0 * d[i] / total);
    cout << fixed << setprecision(6) << ans << "%";
    if (i < int(d.size()) - 1) cout << " ";
  }
  cout << endl;
}

int main() {
  cin.tie(nullptr)->sync_with_stdio(false);
  int tc = 1;
  cin >> tc;
  for (int t = 0; t < tc; ++t) {
    cout << "Case " << t + 1 << ": ";
    solve();
  }
}
