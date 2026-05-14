#include <bits/stdc++.h>
using namespace std;

void solve(int m, int n) {
  vector<vector<pair<int, int>>> al(m);
  for (int i = 0; i < m; ++i) {
    int r;
    cin >> r;
    for (int j = 0; j < r; ++j) {
      int pos;
      cin >> pos;
      al[i].push_back({pos - 1, 0});
    }
    for (int j = 0; j < r; ++j) {
      int x;
      cin >> x;
      al[i][j].second = x;
    }
  }
  vector<vector<pair<int, int>>> ral(n);
  for (int i = 0; i < m; ++i) {
    for (int j = 0; j < int(al[i].size()); ++j) {
      auto [pos, x] = al[i][j];
      ral[pos].push_back({i, x});
    }
  }

  cout << n << ' ' << m << endl;
  for (int i = 0; i < n; ++i) {
    int rsize = int(ral[i].size());
    cout << rsize;
    for (int j = 0; j < rsize; ++j) {
      cout << " " << ral[i][j].first + 1;
    }
    cout << endl;
    for (int j = 0; j < rsize; ++j) {
      cout << ral[i][j].second << " \n"[j == rsize - 1];
    }
    if (rsize == 0) cout << endl;
  }
}

int main() {
  ios::sync_with_stdio(false);
  cin.tie(nullptr);

  int m, n;
  while (cin >> m >> n) {
    solve(m, n);
  }

  return 0;
}
