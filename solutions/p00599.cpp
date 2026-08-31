#include <bits/stdc++.h>
using namespace std;

void solve() {
  string line;
  unordered_map<char, vector<char>> al;
  int count_edge = 0;
  while (getline(cin, line) && line[0] != '*') {
    al[line[1]].push_back(line[3]);
    al[line[3]].push_back(line[1]);
    ++count_edge;
  }
  getline(cin, line);
  int count_vert = (int(line.size()) + 1) / 2;
  int acorns = 0;
  for (int i = 0; i < int(line.size()); i += 2) {
    if (isalpha(line[i]) && al[line[i]].size() == 0) {
      ++acorns;
    }
  }

  cout << "There are " << count_vert - count_edge - acorns << " tree(s) and "
       << acorns << " acorn(s)." << endl;
}

int main() {
  ios::sync_with_stdio(false);
  cin.tie(nullptr);

  int tc = 1;
  cin >> tc;
  string line;
  getline(cin, line);
  while (tc--) solve();

  return 0;
}
