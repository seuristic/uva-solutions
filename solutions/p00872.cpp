#include <bits/stdc++.h>
using namespace std;

int n;
string line, order;

vector<char> vertices;
unordered_map<char, vector<char>> adj;
unordered_map<char, int> indegree, used;

bool found;

void dfs() {
  if (int(order.size()) == n) {
    found = true;

    for (int i = 0; i < n; ++i) {
      if (i > 0) cout << ' ';
      cout << order[i];
    }
    cout << '\n';

    return;
  }

  for (char u : vertices) {
    if (used[u] || indegree[u] > 0) continue;

    used[u] = 1;
    order.push_back(u);

    for (char v : adj[u]) --indegree[v];

    dfs();

    for (char v : adj[u]) ++indegree[v];

    order.pop_back();
    used[u] = 0;
  }
}

void solve() {
  getline(cin, line);

  getline(cin, line);

  order.clear();
  adj.clear();
  vertices.clear();
  indegree.clear();
  used.clear();

  stringstream ss(line);

  char node;
  while (ss >> node) {
    vertices.push_back(node);
  }

  n = vertices.size();

  getline(cin, line);

  ss.clear();
  ss.str(line);

  string condition;

  while (ss >> condition) {
    char u = condition[0];
    char v = condition[2];

    adj[u].push_back(v);
    ++indegree[v];
  }

  found = false;

  dfs();

  if (!found) cout << "NO\n";
}

int main() {
  ios::sync_with_stdio(false);
  cin.tie(nullptr);

  int tc;
  cin >> tc;

  getline(cin, line);

  while (tc--) {
    solve();

    if (tc > 0) cout << '\n';
  }

  return 0;
}
