#include <bits/stdc++.h>
using namespace std;

using ll = long long;

void solve() {
  int n;
  while (cin >> n, n > 0) {
    priority_queue<int, vector<int>, greater<int>> pq;
    while (n--) {
      int x;
      cin >> x;
      pq.push(x);
    }

    int res = 0;
    while (pq.size() > 1) {
      int a = pq.top();
      pq.pop();
      int b = pq.top();
      pq.pop();
      res += a + b;
      pq.push(a + b);
    }

    cout << res << '\n';
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
