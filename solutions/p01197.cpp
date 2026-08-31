#include <bits/stdc++.h>
using namespace std;

class UnionFind {
  int num_sets;
  vector<int> parent, rank, set_size;

public:
  UnionFind(int n) {
    num_sets = n;
    parent.assign(n, 0);
    for (int i = 0; i < n; ++i) parent[i] = i;
    rank.assign(n, 0);
    set_size.assign(n, 1);
  }

  int findSet(int x) {
    return parent[x] == x ? x : parent[x] = findSet(parent[x]);
  }

  bool isSameSet(int x, int y) { return findSet(x) == findSet(y); }

  int numDisjointSets() { return num_sets; }

  int sizeOfSet(int x) { return set_size[findSet(x)]; }

  void unionSet(int x, int y) {
    if (isSameSet(x, y)) return;
    x = findSet(x), y = findSet(y);
    if (rank[x] > rank[y]) swap(x, y);
    parent[x] = y;
    if (rank[x] == rank[y]) ++rank[y];
    set_size[y] += set_size[x];
    --num_sets;
  }
};

void solve() {
  int n, m;
  while (cin >> n >> m && (n || m)) {
    UnionFind uf(n);
    while (m--) {
      int k;
      cin >> k;
      vector<int> a(k);
      for (int& x : a) {
        cin >> x;
      }
      for (int i = 1; i < k; ++i) {
        uf.unionSet(a[0], a[i]);
      }
    }
    cout << uf.sizeOfSet(0) << '\n';
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
