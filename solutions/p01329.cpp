#include <bits/stdc++.h>
using namespace std;

class UnionFind {
  vector<int> p, dist;

public:
  UnionFind(int n) {
    dist.assign(n, 0);
    p.assign(n, 0);
    for (int i = 0; i < n; ++i) p[i] = i;
  }

  int findSet(int x) {
    if (p[x] == x) return x;

    int px = p[x];
    p[x] = findSet(p[x]);
    dist[x] += dist[px];

    return p[x];
  }

  int lenOfSet(int x) { return dist[findSet(x)]; }

  void connect(int x, int y) {
    p[x] = y;
    dist[x] = abs(x - y) % 1000;
  }

  int distToRoot(int x) {
    findSet(x);
    return dist[x];
  }
};

void solve() {
  int n;
  cin >> n;
  UnionFind uf(n + 1);
  char op;
  while (cin >> op && op != 'O') {
    if (op == 'I') {
      int i, j;
      cin >> i >> j;
      uf.connect(i, j);
    } else {
      int i;
      cin >> i;
      cout << uf.distToRoot(i) << '\n';
    }
  }
}

int main() {
  ios::sync_with_stdio(false);
  cin.tie(nullptr);

  int tc = 1;
  cin >> tc;
  while (tc--) solve();

  return 0;
}
