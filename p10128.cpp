#include <bits/stdc++.h>
using namespace std;

const int N = 13;
long long dp[N + 1][N + 1][N + 1];

void precal() {
  dp[1][1][1] = 1;
  for (int n = 2; n <= N; ++n) {
    for (int p = 0; p <= N; ++p) {
      for (int r = 0; r <= N; ++r) {
        dp[n][p][r] = dp[n - 1][p - 1][r] + dp[n - 1][p][r - 1] +
                      (n - 2) * dp[n - 1][p][r];
      }
    }
  }
}

void solve() {
  int n, p, r;
  cin >> n >> p >> r;
  cout << dp[n][p][r] << '\n';
}

int main() {
  ios::sync_with_stdio(false);
  cin.tie(nullptr);

  precal();

  int tc = 1;
  cin >> tc;
  while (tc--) solve();

  return 0;
}
