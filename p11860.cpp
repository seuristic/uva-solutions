#include <bits/stdc++.h>
using namespace std;

void solve(int t) {
  vector<string> words;
  unordered_set<string> word_set;
  unordered_map<string, int> word_map;

  string line;
  while (getline(cin, line) && line != "END") {
    for (int i = 0; i < int(line.length()); ++i) {
      string word = "";
      while (i < int(line.length()) && isalpha(line[i])) {
        word += line[i];
        ++i;
      }
      if (!word.empty()) {
        words.push_back(word);
        word_set.insert(word);
        --i;
      }
    }
  }

  int n = int(words.size());
  int left = 0, right = 0;
  int min_range = INT_MAX, ans_left = -1, ans_right = -1;
  while (right < n) {
    while (right < n && word_map.size() != word_set.size()) {
      ++word_map[words[right]];
      ++right;
    }
    while (left <= right && word_map.size() == word_set.size()) {
      int range = right - left;
      if (min_range > range) {
        min_range = range;
        ans_left = left + 1;
        ans_right = right;
      }
      if (--word_map[words[left]] == 0) {
        word_map.erase(words[left]);
      }
      ++left;
    }
  }

  cout << "Document " << t << ": " << ans_left << " " << ans_right << endl;
}

int main() {
  cin.tie(nullptr)->sync_with_stdio(false);
  int tc = 1;
  cin >> tc;
  for (int t = 1; t <= tc; ++t) {
    solve(t);
  }
}
