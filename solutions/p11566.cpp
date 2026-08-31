#include <bits/stdc++.h>
using namespace std;

using ll = long long;

int N, x, T, K;
vector<int> fav, price;
int memo[1005][105][25];

int f(int rem, int i, int dishes) {
  if (i == K || dishes == 2 * (N + 1)) return 0;
  if (rem < 0) return -1e9;

  int& ans = memo[rem][i][dishes];
  if (ans != -1) return ans;

  ans = f(rem, i + 1, dishes);

  if (rem >= price[i] && dishes + 1 <= 2 * (N + 1))
    ans = max(ans, fav[i] + f(rem - price[i], i + 1, dishes + 1));

  if (rem >= 2 * price[i] && dishes + 2 <= 2 * (N + 1))
    ans = max(ans, 2 * fav[i] + f(rem - 2 * price[i], i + 1, dishes + 2));

  return ans;
}

void solve() {
  while ((cin >> N >> x >> T >> K) && (N || x || T || K)) {
    fav.assign(K, 0), price.assign(K, 0);
    for (int i = 0; i < K; ++i) {
      cin >> price[i];
      for (int j = 0; j < N + 1; ++j) {
        int f;
        cin >> f;
        fav[i] += f;
      }
    }

    int p = N + 1;
    int budget = (10 * p * x) / 11 - p * T;
    memset(memo, -1, sizeof memo);
    cout << setprecision(2) << fixed << f(budget, 0, 0) / (N + 1.0) << '\n';
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
