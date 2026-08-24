#include <bits/stdc++.h>
using namespace std;

using ll = long long;

void solve() {
  int n;
  cin >> n;
  vector<string> a(n);
  for (string& s : a) {
    cin >> s;
  }

  int cuts = 0, mask = 0;
  for (int i = 0; i < n; ++i) {
    if (mask == 0) {
      for (const char& c : a[i]) mask |= 1 << (c - 'a');
    } else {
      int mask2 = 0;
      for (const char& c : a[i]) mask2 |= 1 << (c - 'a');
      mask &= mask2;
      if (mask == 0) {
        mask = mask2;
        ++cuts;
      }
    }
  }

  cout << cuts << '\n';
}

int main() {
  ios::sync_with_stdio(false);
  cin.tie(nullptr);

  int tc = 1;
  cin >> tc;
  while (tc--) solve();

  return 0;
}
