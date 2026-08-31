#include <bits/stdc++.h>
using namespace std;

void solve() {
  string s;
  set<string> dict;
  while (cin >> s) {
    int i = 0, n = int(s.length());
    while (i < n) {
      string word = "";
      bool flag = false;
      while (i < n && isalpha(s[i])) {
        word += tolower(s[i]);
        flag = true;
        ++i;
      }
      if (word.length() > 0) {
        dict.insert(word);
      }
      if (!flag) ++i;
    }
  }

  for (string word : dict) {
    cout << word << endl;
  }
}

int main() {
  cin.tie(nullptr)->sync_with_stdio(false);
  int tc = 1;
  // cin >> tc;
  while (tc--) solve();
}
