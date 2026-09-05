#include <bits/stdc++.h>
using namespace std;

using ll = long long;

const int INF = 1e9;

int n;
vector<unordered_map<int, int>> adj;
vector<int> costs;

int f(int rem) {
  if (rem == 0) return 0;
  if (rem < 0) return INF;

  vector<int> dp(rem + 1, INF);
  dp[0] = 0;

  for (int x = 1; x <= rem; ++x) {
    for (int& c : costs) {
      if (x >= 2 * c && dp[x - 2 * c] != INF) {
        dp[x] = min(dp[x], 2 + dp[x - 2 * c]);
      }
    }
  }

  return dp[rem];
}

bool dfs(int prev, int u, int dest, vector<int>& p) {
  if (u == dest) return true;

  for (const auto& [v, w] : adj[u]) {
    if (prev == v) continue;

    p[v] = u;
    if (dfs(u, v, dest, p)) return true;
  }

  return false;
}

void solve() {
  int m;
  cin >> n >> m;
  adj.assign(n + 1, {});
  for (int i = 0; i < m; ++i) {
    int u, v, c;
    cin >> u >> v >> c;

    adj[u][v] = c;
    adj[v][u] = c;
  }

  int k;
  cin >> k;
  while (k--) {
    int u, v, budget;
    cin >> u >> v >> budget;

    vector<int> p(n + 1, -1), path{v};

    dfs(-1, u, v, p);

    while (v != u) {
      path.push_back(p[v]);
      v = p[v];
    }

    costs.clear();

    int total_cost = 0;

    for (int i = 0; i < int(path.size()) - 1; ++i) {
      int c = adj[path[i]][path[i + 1]];
      total_cost += c;

      if (i > 0) costs.push_back(c);
    }

    if (budget < total_cost) {
      cout << "No\n";
      continue;
    }

    int rem = budget - total_cost;
    int res = f(rem);

    if (res == INF) cout << "No\n";
    else cout << "Yes " << res + path.size() - 1 << '\n';
  }
}

int main() {
  ios::sync_with_stdio(false);
  cin.tie(nullptr);

  int tc = 1;
  cin >> tc;
  while (tc--) {
    solve();

    if (tc) cout << '\n';
  }

  return 0;
}
