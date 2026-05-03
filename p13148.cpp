#include <bits/stdc++.h>
using namespace std;

int main() {
  cin.tie(nullptr)->sync_with_stdio(false);
  unordered_set<int> special = {
      1,        64,       729,      4096,     15625,    46656,    117649,
      262144,   531441,   1000000,  1771561,  2985984,  4826809,  7529536,
      11390625, 16777216, 24137569, 34012224, 47045881, 64000000, 85766121
  };
  int n;
  while (cin >> n && n) {
    cout << ((special.count(n)) ? "Special" : "Ordinary") << endl;
  }
}
