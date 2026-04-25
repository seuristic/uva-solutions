#include <bits/stdc++.h>
using namespace std;

void solve() {
  string s;
  cin >> s;
  vector<int> v(3, 0);
  int section = 0;
  bool is_valid_structure = true;
  int e_count = 0, m_count = 0;
  for (char& c : s) {
    if (c == '?') {
      ++v[section];
    } else if (c == 'M') {
      section = 1;
      ++m_count;
    } else if (c == 'E') {
      section = 2;
      ++e_count;
    } else {
      is_valid_structure = false;
      break;
    }
  }

  if (is_valid_structure && m_count == 1 && e_count == 1 && v[0] > 0 &&
      v[1] > 0 && v[2] > 0 && (v[0] + v[1] == v[2])) {
    cout << "theorem" << endl;
  } else {
    cout << "no-theorem" << endl;
  }
}

int main() {
  cin.tie(nullptr)->sync_with_stdio(false);
  int tc = 1;
  cin >> tc;
  while (tc--) solve();
}
