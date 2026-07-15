#include <bits/stdc++.h>
using namespace std;

// RANGE MIN-QUERY
// class SegmentTree {
// private:
//   int n;
//   vector<int> a, tree, lazy;

//   int left(int p) { return p << 1; }
//   int right(int p) { return (p << 1) + 1; }

//   int conquer(int a, int b) {
//     if (a == -1) return b;
//     if (b == -1) return a;
//     return min(a, b);
//   }

//   void build(int p, int l, int r) {
//     if (l == r) tree[p] = a[l];
//     else {
//       int m = (l + r) / 2;
//       build(left(p), l, m);
//       build(right(p), m + 1, r);
//       tree[p] = conquer(tree[left(p)], tree[right(p)]);
//     }
//   }

//   void propagate(int p, int l, int r) {
//     if (lazy[p] != -1) {
//       tree[p] = lazy[p];
//       if (l == r) a[l] = lazy[p];
//       else lazy[left(p)] = lazy[right(p)] = lazy[p];
//       lazy[p] = -1;
//     }
//   }

//   void update(int p, int l, int r, int i, int j, int val) {
//     propagate(p, l, r);
//     if (i > j) return;
//     if (i <= l && r <= j) {
//       lazy[p] = val;
//       propagate(p, l, r);
//     } else {
//       int m = (l + r) / 2;
//       update(left(p), l, m, i, min(m, j), val);
//       update(right(p), m + 1, r, max(i, m + 1), j, val);

//       int left_subtree = (lazy[left(p)] != -1) ? lazy[left(p)] :
//       tree[left(p)]; int right_subtree =
//           (lazy[right(p)] != -1) ? lazy[right(p)] : tree[right(p)];

//       tree[p] =
//           (left_subtree <= right_subtree) ? tree[left(p)] : tree[right(p)];
//     }
//   }

//   int rmq(int p, int l, int r, int i, int j) {
//     propagate(p, l, r);
//     if (i > j) return -1;
//     if (i <= l && r <= j) return tree[p];
//     int m = (l + r) / 2;
//     return conquer(
//         rmq(left(p), l, m, i, min(m, j)),
//         rmq(right(p), m + 1, r, max(i, m + 1), j)
//     );
//   }

// public:
//   SegmentTree(int sz) : n(sz), tree(4 * n), lazy(4 * n, -1) {}
//   SegmentTree(const vector<int>& initial_a)
//       : SegmentTree((int)initial_a.size()) {
//     a = initial_a;
//     build(1, 0, n - 1);
//   }

//   void update(int i, int j, int val) { update(1, 0, n - 1, i, j, val); }

//   int rmq(int i, int j) { return rmq(1, 0, n - 1, i, j); }
// };

// RANGE SUM-QUERY
class SegmentTree {
private:
  int n;
  vector<int> tree;
  vector<char> lazy;

  int left(int p) { return p << 1; }
  int right(int p) { return (p << 1) + 1; }

  int combine(char old_op, char new_op) {
    if (new_op == 'F') return 'F';
    if (new_op == 'E') return 'E';

    if (old_op == 'I') return 'N';
    if (old_op == 'N') return 'I';
    if (old_op == 'F') return 'E';
    if (old_op == 'E') return 'F';

    return 'N';
  }

  void build(int p, int l, int r, const vector<int>& a) {
    if (l == r) {
      tree[p] = a[l];
      return;
    }

    int m = (l + r) / 2;
    build(left(p), l, m, a);
    build(right(p), m + 1, r, a);
    tree[p] = tree[left(p)] + tree[right(p)];
  }

  void apply(int p, int l, int r, char op) {
    int len = r - l + 1;

    if (op == 'F') tree[p] = len;
    else if (op == 'E') tree[p] = 0;
    else if (op == 'I') tree[p] = len - tree[p];

    lazy[p] = combine(lazy[p], op);
  }

  void propagate(int p, int l, int r) {
    if (lazy[p] == 'N' || l == r) return;

    int m = (l + r) / 2;
    apply(left(p), l, m, lazy[p]);
    apply(right(p), m + 1, r, lazy[p]);

    lazy[p] = 'N';
  }

  void update(int p, int l, int r, int i, int j, char op) {
    propagate(p, l, r);
    if (i > r || j < l) return;
    if (i <= l && r <= j) {
      apply(p, l, r, op);
      return;
    }

    int m = (l + r) / 2;
    update(left(p), l, m, i, j, op);
    update(right(p), m + 1, r, i, j, op);

    tree[p] = tree[left(p)] + tree[right(p)];
  }

  int rsq(int p, int l, int r, int i, int j) {
    if (i > r || j < l) return 0;
    if (i <= l && r <= j) return tree[p];

    propagate(p, l, r);

    int m = (l + r) / 2;
    return rsq(left(p), l, m, i, min(m, j)) +
           rsq(right(p), m + 1, r, max(i, m + 1), j);
  }

public:
  SegmentTree(int sz) : n(sz), tree(4 * n), lazy(4 * n, 'N') {}
  SegmentTree(const vector<int>& a) : SegmentTree((int)a.size()) {
    build(1, 0, n - 1, a);
  }

  void update(int i, int j, char op) { update(1, 0, n - 1, i, j, op); }

  int rsq(int i, int j) { return rsq(1, 0, n - 1, i, j); }
};

void solve() {
  int m;
  cin >> m;
  vector<int> pirates;
  while (m--) {
    int t;
    string s;
    cin >> t >> s;
    while (t--) {
      for (char c : s) {
        pirates.push_back(c - '0');
      }
    }
  }

  SegmentTree st(pirates);

  int q, qno = 1;
  cin >> q;
  while (q--) {
    char op;
    int a, b;
    cin >> op >> a >> b;
    if (op == 'S') cout << "Q" << qno++ << ": " << st.rsq(a, b) << endl;
    else st.update(a, b, op);
  }
}

int main() {
  ios::sync_with_stdio(false);
  cin.tie(nullptr);

  int tc = 1;
  cin >> tc;
  for (int i = 1; i <= tc; ++i) {
    cout << "Case " << i << ":\n";
    solve();
  }

  return 0;
}
