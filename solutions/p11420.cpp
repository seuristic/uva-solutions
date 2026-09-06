#include <bits/stdc++.h>
using namespace std;

using ll = long long;

int n, s;
ll memo[5][70][70];

ll f(int prev, int ind, int cnt) {
  if (ind == n) {
    if (cnt == s) return 1;
    return 0;
  }

  ll& ans = memo[prev][ind][cnt];
  if (ans != -1) return ans;

  return ans = f(0, ind + 1, cnt) + f(1, ind + 1, cnt + prev);
}

void solve() {
  while ((cin >> n >> s) && (n >= 0 || s >= 0)) {
    memset(memo, -1, sizeof memo);

    cout << f(1, 0, 0) << '\n';  // 0 -> U, 1 -> L
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
