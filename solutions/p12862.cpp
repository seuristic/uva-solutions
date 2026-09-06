#include <bits/stdc++.h>
using namespace std;

using ll = long long;

int n, f;
vector<bool> friends;
vector<vector<pair<int, int>>> adj;

ll total;

bool dfs(int u) {
  bool is_friend = friends[u];

  for (auto& [v, w] : adj[u]) {
    if (dfs(v)) {
      is_friend = true;
      total += w;
    }
  }

  return is_friend;
}

void solve() {
  while (cin >> n >> f) {
    adj.assign(n, {});
    friends.assign(n, false);

    vector<ll> dp(n, 0);

    for (int i = 0; i < n - 1; ++i) {
      int a, b, c;
      cin >> a >> b >> c;

      --a, --b;

      adj[a].push_back({b, c});

      dp[b] = dp[a] + c;
    }

    ll best = 0;

    for (int i = 0; i < f; ++i) {
      int node;
      cin >> node;

      --node;

      friends[node] = true;
      best = max(best, dp[node]);
    }

    total = 0;

    dfs(0);

    cout << total - best << '\n';
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
