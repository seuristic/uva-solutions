#include <bits/stdc++.h>
using namespace std;

using ll = long long;

void solve() {
  int dx, dy, n, q;
  int tc = 1;
  while (cin >> dx >> dy >> n >> q) {
    if (!dx && !dy && !n && !q) {
      return;
    }

    int U = dx + dy, V = U;
    vector<vector<int>> pref(U + 1, vector<int>(V + 1, 0));
    for (int i = 0; i < n; ++i) {
      int x, y;
      cin >> x >> y;
      int u = x + y, v = x - y + dy;
      ++pref[u][v];
    }

    for (int u = 1; u <= U; ++u) {
      for (int v = 1; v <= V; ++v) {
        pref[u][v] += pref[u - 1][v] + pref[u][v - 1] - pref[u - 1][v - 1];
      }
    }

    auto query = [&](int u1, int u2, int v1, int v2) {
      u1 = max(u1, 1);
      u2 = min(u2, U);
      v1 = max(v1, 1);
      v2 = min(v2, V);

      if (u1 > u2 || v1 > v2) return 0;

      return pref[u2][v2] - pref[u1 - 1][v2] - pref[u2][v1 - 1] +
             pref[u1 - 1][v1 - 1];
    };

    cout << "Case " << tc++ << ":\n";
    while (q--) {
      int m;
      cin >> m;
      int best_count = -1;
      int best_x = -1, best_y = -1;
      for (int y = 1; y <= dy; ++y) {
        for (int x = 1; x <= dx; ++x) {
          int u = x + y;
          int v = x - y + dy;
          int count = query(u - m, u + m, v - m, v + m);
          if (count > best_count) {
            best_count = count;
            best_x = x;
            best_y = y;
          }
        }
      }

      cout << best_count << " (" << best_x << "," << best_y << ")\n";
    }
  }
}

int main() {
  ios::sync_with_stdio(false);
  cin.tie(nullptr);

  solve();

  return 0;
}
