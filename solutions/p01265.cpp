#include <bits/stdc++.h>
using namespace std;

using ll = long long;
using Edge = tuple<int, int, int>;

class UnionFind {
  int num_sets;
  vector<int> p, rank, set_size;

public:
  UnionFind(int n) {
    num_sets = n;
    p.assign(n, 0);
    for (int i = 0; i < n; ++i) p[i] = i;
    rank.assign(n, 0);
    set_size.assign(n, 1);
  }

  int findSet(int x) { return p[x] == x ? x : p[x] = findSet(p[x]); }

  bool isSameSet(int x, int y) { return findSet(x) == findSet(y); }

  int numDisjointSets() { return num_sets; }

  int sizeOfSet(int x) { return set_size[findSet(x)]; }

  bool unionSet(int x, int y) {
    x = findSet(x), y = findSet(y);
    if (x == y) return false;
    if (rank[x] > rank[y]) swap(x, y);
    p[x] = y;
    if (rank[x] == rank[y]) ++rank[y];
    set_size[y] += set_size[x];
    --num_sets;
    return true;
  }
};

void solve() {
  int n, m;
  cin >> n >> m;

  vector<Edge> el(m);
  vector<vector<pair<int, int>>> al(n);
  for (int i = 0; i < m; ++i) {
    int u, v, w;
    cin >> u >> v >> w;

    --u, --v;

    el[i] = {w, u, v};
    al[u].push_back({v, w});
    al[v].push_back({u, w});
  }

  sort(el.rbegin(), el.rend());

  int ans = 0;
  UnionFind uf(n);

  auto isCandidate = [&](int root) {
    int min_inside = INT_MAX;
    int max_border = 0;

    for (int u = 0; u < n; ++u) {
      if (uf.findSet(u) != root) continue;

      for (auto [v, w] : al[u]) {
        if (uf.findSet(v) == root) {
          min_inside = min(min_inside, w);
        } else {
          max_border = max(max_border, w);
        }
      }
    }

    return min_inside > max_border;
  };

  for (auto& [w, u, v] : el) {
    if (!uf.unionSet(u, v)) continue;

    int root = uf.findSet(u);

    if (isCandidate(root)) {
      ans += uf.sizeOfSet(root);
    }
  }

  cout << ans << '\n';
}

int main() {
  ios::sync_with_stdio(false);
  cin.tie(nullptr);

  int tc = 1;
  cin >> tc;
  while (tc--) solve();

  return 0;
}
