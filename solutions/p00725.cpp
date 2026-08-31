#include <bits/stdc++.h>
using namespace std;

vector<int> calMask(int a, int& mask) {
  vector<int> dig;
  while (a) {
    mask |= (1 << (a % 10));
    dig.push_back(a % 10);
    a /= 10;
  }
  return dig;
}

void solve() {
  int n;
  bool first_test_case = false;
  while (cin >> n, n > 0) {
    if (first_test_case) cout << '\n';
    else first_test_case = true;

    bool found = false;
    for (int fghij = 1234; fghij <= 98765 / n; ++fghij) {
      int abcde = fghij * n;
      int tmp, used = (fghij < 10000);
      tmp = abcde;
      while (tmp) {
        used |= 1 << (tmp % 10);
        tmp /= 10;
      }
      tmp = fghij;
      while (tmp) {
        used |= 1 << (tmp % 10);
        tmp /= 10;
      }
      if (used == (1 << 10) - 1) {
        cout << abcde << " / " << setw(5) << setfill('0') << fghij << " = " << n
             << '\n';
        found = true;
      }
    }
    if (!found) cout << "There are no solutions for " << n << ".\n";
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
