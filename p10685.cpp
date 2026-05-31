#include <bits/stdc++.h>
using namespace std;

class UnionFind {
  int max_set_size;
  vector<int> p, rank, set_size;

public:
  UnionFind(int n) {
    max_set_size = 1;
    p.resize(n + 1);
    rank.assign(n + 1, 0);
    set_size.assign(n + 1, 1);
    for (int i = 0; i <= n; ++i) p[i] = i;
  }

  int findSet(int x) { return (p[x] == x) ? x : (p[x] = findSet(p[x])); }

  void unionSet(int x, int y) {
    int px = findSet(x);
    int py = findSet(y);

    if (px == py) return;

    if (rank[px] > rank[py]) swap(px, py);

    p[px] = py;
    set_size[py] += set_size[px];

    if (rank[px] == rank[py]) ++rank[py];

    if (max_set_size < set_size[py]) {
      max_set_size = set_size[py];
    }
  }

  int maxSizeOfSet() { return max_set_size; }
};

void solve() {
  int c, r;
  while (cin >> c >> r && (c || r)) {
    UnionFind uf(c);
    unordered_map<string, int> hmap;
    int cnt = 0;
    for (int i = 0; i < c; ++i) {
      string name;
      cin >> name;
      hmap[name] = ++cnt;
    }
    for (int i = 0; i < r; ++i) {
      string a1, a2;
      cin >> a1 >> a2;
      int x = hmap[a1];
      int y = hmap[a2];
      uf.unionSet(x, y);
    }
    cout << uf.maxSizeOfSet() << '\n';
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
