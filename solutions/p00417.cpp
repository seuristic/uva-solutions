#include <bits/stdc++.h>
using namespace std;

unordered_map<string, int> word_index;

void precompute() {
  int index = 1;
  queue<string> q;
  for (char c = 'a'; c <= 'z'; ++c) {
    q.push(string(1, c));
  }
  while (!q.empty()) {
    string w = q.front();
    q.pop();
    word_index[w] = index++;
    if (w.length() == 5) continue;
    for (char c = w.back() + 1; c <= 'z'; ++c) {
      q.push(w + string(1, c));
    }
  }
}

void solve() {
  string s;
  while (cin >> s) {
    if (word_index.count(s)) {
      cout << word_index[s] << endl;
    } else {
      cout << 0 << endl;
    }
  }
}

int main() {
  cin.tie(nullptr)->sync_with_stdio(false);
  precompute();
  int tc = 1;
  // cin >> tc;
  while (tc--) solve();
}
