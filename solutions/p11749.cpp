#include <bits/stdc++.h>
using namespace std;

using ll = long long;

enum { UNVISITED = -1, VISITED = -2 };

int n, m;
ll max_ppa;

vector<vector<pair<int, ll>>> adj;
vector<int> dfs_num;

int dfs(int u) {
  dfs_num[u] = VISITED;

  int count = 0;

  for (auto& [v, w] : adj[u]) {
    if (dfs_num[v] == UNVISITED && w == max_ppa) {
      count += 1 + dfs(v);
    }
  }

  return count;
}

void solve() {
  while ((cin >> n >> m) && (n || m)) {
    max_ppa = LLONG_MIN;
    adj.assign(n, {});
    dfs_num.assign(n, UNVISITED);

    while (m--) {
      int u, v;
      ll w;
      cin >> u >> v >> w;

      --u, --v;

      adj[u].push_back({v, w});
      adj[v].push_back({u, w});

      max_ppa = max(max_ppa, w);
    }

    int ans = 0;

    for (int u = 0; u < n; ++u) {
      if (dfs_num[u] == UNVISITED) {
        ans = max(ans, 1 + dfs(u));
      }
    }

    cout << ans << '\n';
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
