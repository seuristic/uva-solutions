#include <bits/stdc++.h>
using namespace std;

using ll = long long;

enum { UNVISITED = -1, VISITED = -2 };

int p, t, dfs_cnt, scc_cnt;
vector<vector<int>> al;
unordered_map<string, int> name_to_node_map;
unordered_map<string, int> node_to_name_map;
vector<int> dfs_num, dfs_low;
vector<bool> visited;
stack<int> st;

void tarjan(int u) {
  dfs_num[u] = dfs_low[u] = ++dfs_cnt;
  visited[u] = true;
  st.push(u);

  for (int v : al[u]) {
    if (dfs_num[v] == UNVISITED) tarjan(v);
    if (visited[v]) dfs_low[u] = min(dfs_low[u], dfs_low[v]);
  }

  if (dfs_low[u] == dfs_num[u]) {
    ++scc_cnt;
    while (1) {
      int v = st.top();
      st.pop();
      visited[v] = false;
      if (u == v) break;
    }
  }
}

void solve() {
  string line;
  while (cin >> p >> t && (p || t)) {
    getline(cin, line);

    dfs_cnt = scc_cnt = 0;
    al.assign(p, {});
    name_to_node_map.clear();
    dfs_num.assign(p, UNVISITED);
    dfs_low.assign(p, 0);
    visited.assign(p, false);

    while (!st.empty()) st.pop();

    for (int i = 0; i < p; ++i) {
      getline(cin, line);
      name_to_node_map[line] = i;
    }

    for (int i = 0; i < t; ++i) {
      getline(cin, line);
      int u = name_to_node_map[line];
      getline(cin, line);
      int v = name_to_node_map[line];
      al[u].push_back(v);
    }

    for (int u = 0; u < p; ++u) {
      if (dfs_num[u] == UNVISITED) {
        tarjan(u);
      }
    }

    cout << scc_cnt << '\n';
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
