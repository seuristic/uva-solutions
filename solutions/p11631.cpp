#include <bits/stdc++.h>
using namespace std;

using ll = long long;
using Edge = tuple<int, int, int>;

void solve() {
  int n, m;
  while (cin >> n >> m && (n || m)) {
    vector<vector<pair<int, int>>> al(n);
    priority_queue<Edge, vector<Edge>, greater<Edge>> pq;
    vector<int> visited(n);

    int total_cost = 0, mst_cost = 0;

    for (int i = 0; i < m; ++i) {
      int u, v, w;
      cin >> u >> v >> w;

      total_cost += w;

      al[u].push_back({v, w});
      al[v].push_back({u, w});
    }

    pq.push({0, 0, 0});

    while (!pq.empty()) {
      auto [w, u, v] = pq.top();
      pq.pop();

      if (visited[v]) continue;
      visited[v] = 1;

      mst_cost += w;

      for (const auto& [node, weight] : al[v]) {
        if (!visited[node]) {
          pq.push({weight, v, node});
        }
      }
    }

    cout << total_cost - mst_cost << '\n';
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
