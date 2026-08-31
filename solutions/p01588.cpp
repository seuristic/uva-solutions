#include <bits/stdc++.h>
using namespace std;

bool isInvalid(char c1, char c2) {
  return c1 == '2' && c2 == '2';
}

void solve() {
  string a, b;
  while (cin >> a >> b) {
    int n = a.size(), m = b.size();
    if (n > m) {
      swap(n, m);
      swap(a, b);
    }

    int ans = n + m;

    // case 1
    for (int overlap = 1; overlap <= n; ++overlap) {
      int i = n - overlap, j = 0;
      bool flag = true;
      for (int cnt = 0; cnt < overlap; ++cnt) {
        if (isInvalid(a[i], b[j])) {
          flag = false;
          break;
        }
        ++i, ++j;
      }
      if (flag) ans = min(ans, m + n - overlap);
    }

    // case 2
    for (int pos = 1; pos <= m - n - 1; ++pos) {
      int i = 0, j = pos;
      bool flag = true;
      for (int cnt = 0; cnt < n; ++cnt) {
        if (isInvalid(a[i], b[j])) {
          flag = false;
          break;
        }
        ++i, ++j;
      }
      if (flag) ans = min(ans, m);
    }

    // case 3
    for (int overlap = n; overlap >= 1; --overlap) {
      int i = 0, j = m - overlap;
      bool flag = true;
      for (int cnt = 0; cnt < overlap; ++cnt) {
        if (isInvalid(a[i], b[j])) {
          flag = false;
          break;
        }
        ++i, ++j;
      }
      if (flag) ans = min(ans, m + n - overlap);
    }

    cout << ans << endl;
  }
}

void solve2() {
  string a, b;
  while (cin >> a >> b) {
    int n = a.size(), m = b.size();
    int ans = n + m;
    for (int shift = -m; shift <= n; ++shift) {
      bool ok = true;

      for (int j = 0; j < m && ok; ++j) {
        int i = j + shift;
        if (0 <= i && i < n && a[i] == '2' && b[j] == '2') {
          ok = false;
        }
      }

      if (ok) {
        int left = min(0, shift);
        int right = max(n, m + shift);
        ans = min(ans, right - left);
      }
    }
    cout << ans << endl;
  }
}

int main() {
  ios::sync_with_stdio(false);
  cin.tie(nullptr);

  // solve();
  solve2();

  return 0;
}
