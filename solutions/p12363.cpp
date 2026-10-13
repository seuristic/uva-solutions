#include <bits/stdc++.h>
using namespace std;

using ll = long long;

enum { UNVISITED = -1, VISITED = -2 };

int r, c, q, dfs_cnt, comp_cnt;
vector<vector<pair<int, int>>> al;
vector<int> dfs_low, dfs_num, comp;
vector<bool> is_bridge;

void dfs(int u, int parent_id = -1) {
  dfs_low[u] = dfs_num[u] = ++dfs_cnt;

  for (auto [v, id] : al[u]) {
    if (id == parent_id) continue;

    if (dfs_num[v] == UNVISITED) {
      dfs(v, id);

      if (dfs_low[v] > dfs_num[u]) is_bridge[id] = true;

      dfs_low[u] = min(dfs_low[u], dfs_low[v]);
    } else {
      dfs_low[u] = min(dfs_low[u], dfs_num[v]);
    }
  }
}

void dfs2(int u, int comp_cnt) {
  comp[u] = comp_cnt;

  for (auto [v, id] : al[u]) {
    if (is_bridge[id] && comp[v] == -1) {
      dfs2(v, comp_cnt);
    }
  }
}

void solve() {
  while (cin >> r >> c >> q && (r || c || q)) {
    dfs_cnt = 0;
    al.assign(r, {});
    dfs_low.assign(r, 0);
    dfs_num.assign(r, UNVISITED);
    is_bridge.assign(c, false);
    comp.assign(r, -1);

    for (int i = 0; i < c; ++i) {
      int a, b;
      cin >> a >> b;

      --a, --b;

      al[a].push_back({b, i});
      al[b].push_back({a, i});
    }

    for (int u = 0; u < r; ++u) {
      if (dfs_num[u] == UNVISITED) {
        dfs(u);
      }
    }

    comp_cnt = 0;
    for (int u = 0; u < r; ++u) {
      if (comp[u] == -1) {
        dfs2(u, ++comp_cnt);
      }
    }

    while (q--) {
      int s, t;
      cin >> s >> t;

      --s, --t;

      cout << (comp[s] == comp[t] ? 'Y' : 'N') << '\n';
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
