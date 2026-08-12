#include <bits/stdc++.h>

#include <climits>
using namespace std;

using ll = long long;

vector<ll> a, pref;

void dfs(int left, int right) {
  if (left > right) return;

  ll best_diff = LLONG_MAX;
  ll best_left_sum = LLONG_MIN;
  ll best = left;

  for (int i = left; i <= right; ++i) {
    if (i < right && a[i] == a[i + 1]) continue;

    ll left_sum = pref[i] - pref[left];
    ll right_sum = pref[right + 1] - pref[i + 1];
    ll diff = llabs(right_sum - left_sum);

    if (diff < best_diff || (diff == best_diff && left_sum > best_left_sum)) {
      best = i;
      best_diff = diff;
      best_left_sum = left_sum;
    }
  }

  cout << a[best];

  if (left != right) {
    cout << '(';

    dfs(left, best - 1);

    if (best != left && best != right) cout << ',';

    dfs(best + 1, right);

    cout << ')';
  }
}

void solve() {
  int n;
  cin >> n;
  a.resize(n), pref.resize(n + 1);
  for (int i = 0; i < n; ++i) {
    cin >> a[i];
  }

  sort(a.begin(), a.end());

  for (int i = 0; i < n; ++i) {
    pref[i + 1] = pref[i] + a[i];
  }

  dfs(0, n - 1);
  cout << '\n';
}

int main() {
  ios::sync_with_stdio(false);
  cin.tie(nullptr);

  int tc = 1;
  cin >> tc;
  for (int t = 1; t <= tc; ++t) {
    cout << "Case #" << t << ": ";
    solve();
  }

  return 0;
}
