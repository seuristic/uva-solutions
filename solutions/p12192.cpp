#include <bits/stdc++.h>
using namespace std;

int n, m;
vector<vector<int>> h_area;

void solve() {
  while (cin >> n >> m, n || m) {
    h_area.assign(n, vector<int>(m));
    for (int i = 0; i < n; ++i) {
      for (int j = 0; j < m; ++j) {
        cin >> h_area[i][j];
      }
    }

    int q;
    cin >> q;
    while (q--) {
      int l, u;
      cin >> l >> u;
      int ans = 0;
      for (int r = n - 1; r >= 0; --r) {
        int len = min(n - r, m);
        int left = 0, right = len;
        while (left < right) {
          int mid = left + (right - left) / 2;
          if (h_area[r + mid][mid] < l) {
            left = mid + 1;
          } else {
            right = mid;
          }
        }

        int left_len = left;
        left = 0, right = len;
        while (left < right) {
          int mid = left + (right - left) / 2;
          if (h_area[r + mid][mid] <= u) {
            left = mid + 1;
          } else {
            right = mid;
          }
        }

        int right_len = right;
        ans = max(ans, right_len - left_len);
      }
      for (int c = m - 1; c >= 0; --c) {
        int len = min(n, m - c);
        int left = 0, right = len;
        while (left < right) {
          int mid = left + (right - left) / 2;
          if (h_area[mid][c + mid] < l) {
            left = mid + 1;
          } else {
            right = mid;
          }
        }

        int left_len = left;
        left = 0, right = len;
        while (left < right) {
          int mid = left + (right - left) / 2;
          if (h_area[mid][c + mid] <= u) {
            left = mid + 1;
          } else {
            right = mid;
          }
        }

        int right_len = right;
        ans = max(ans, right_len - left_len);
      }
      cout << ans << '\n';
    }
    cout << "-\n";
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
