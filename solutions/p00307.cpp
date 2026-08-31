#include <bits/stdc++.h>
using namespace std;

int n, sum;
vector<int> a;
vector<bool> used;

bool f(int start, int curr, int completed, int target) {
  if (completed * target == sum) return true;
  if (curr == target) return f(0, 0, completed + 1, target);

  int prev = -1;
  for (int i = start; i < n; ++i) {
    if (used[i]) continue;
    if (a[i] == prev) continue;
    if (curr + a[i] > target) continue;

    used[i] = true;

    if (f(i, curr + a[i], completed, target)) return true;

    used[i] = false;

    prev = a[i];

    if (curr == 0) return false;
    if (curr + a[i] == target) return false;
  }

  return false;
}

void solve() {
  while (cin >> n, n > 0) {
    a.resize(n);
    for (int& x : a) cin >> x;
    sort(a.rbegin(), a.rend());
    sum = accumulate(a.begin(), a.end(), 0);
    for (int target = a[0]; target <= sum; ++target) {
      if (sum % target != 0) continue;

      used.assign(n, false);
      if (f(0, 0, 0, target)) {
        cout << target << '\n';
        break;
      }
    }
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
