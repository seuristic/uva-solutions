#include <bits/stdc++.h>
using namespace std;

void solve() {
  int n;
  cin >> n;
  vector<int> cnt(10);
  for (int x = 1; x <= n; ++x) {
    int tmp = x;
    while (tmp) {
      ++cnt[tmp % 10];
      tmp /= 10;
    }
  }

  for (int i = 0; i < 10; ++i) {
    cout << cnt[i] << " \n"[i == 9];
  }
}

int main() {
  ios::sync_with_stdio(false);
  cin.tie(nullptr);

  int tc = 1;
  cin >> tc;
  while (tc--) solve();

  return 0;
}
