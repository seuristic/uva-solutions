#include <bits/stdc++.h>
using namespace std;

using ll = long long;

int n;
vector<int> w, can;
vector<ll> memo;

ll f(int mask) {
  if (mask == (1 << (n + 1)) - 1) return 1;

  ll& ans = memo[mask];

  if (ans != -1) return ans;

  ans = 0;

  ll available = can[mask] & ~mask;

  for (int v = 1; v <= n; ++v) {
    if (mask & (1 << v)) continue;

    if (available & (1 << v)) {
      ans += f(mask | (1 << v));
    }
  }

  return ans;
}

void solve() {
  cin >> n;

  w.assign(n + 1, 0);

  string row;

  for (int i = 0; i <= n; ++i) {
    cin >> row;

    for (int j = 0; j < n; ++j) {
      if (row[j] == '1') w[i] |= (1 << (j + 1));
    }
  }

  ll states = 1 << (n + 1);

  memo.assign(states, -1);
  can.assign(states, 0);

  for (ll mask = 1; mask < states; ++mask) {
    int bit = __builtin_ctz(mask);
    int prev = mask & (mask - 1);
    can[mask] = can[prev] | w[bit];
  }

  cout << f(1) << '\n';
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
