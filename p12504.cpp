#include <bits/stdc++.h>
using namespace std;

map<string, string> parseDict(string& dict) {
  map<string, string> res;
  int n = int(dict.length());
  for (int i = 0; i < n; ++i) {
    if (dict[i] == '{' || dict[i] == '}') {
      continue;
    } else {
      string dkey = "";
      int j = i;
      while (dict[j] != ':') {
        dkey += dict[j];
        ++j;
      }
      string dval = "";
      ++j;
      while (isdigit(dict[j])) {
        dval += dict[j];
        ++j;
      }
      res[dkey] = dval;
      if (dict[j] == ',') i = j;
      else i = j - 1;
    }
  }

  return res;
}

void solve() {
  string old_dict_raw, new_dict_raw;
  cin >> old_dict_raw >> new_dict_raw;

  auto old_dict = parseDict(old_dict_raw);
  auto new_dict = parseDict(new_dict_raw);

  vector<string> added_keys, deleted_keys, changed_value_keys;
  for (auto& [k, v] : new_dict) {
    if (!old_dict.count(k)) {
      added_keys.push_back(k);
    } else if (old_dict[k] != v) {
      changed_value_keys.push_back(k);
    }
  }
  for (auto& [k, v] : old_dict) {
    if (!new_dict.count(k)) {
      deleted_keys.push_back(k);
    }
  }

  if (!added_keys.empty()) {
    cout << "+";
    int n = int(added_keys.size());
    for (int i = 0; i < n; ++i) {
      cout << added_keys[i];
      if (i < n - 1) cout << ",";
    }
    cout << endl;
  }

  if (!deleted_keys.empty()) {
    cout << "-";
    int n = int(deleted_keys.size());
    for (int i = 0; i < n; ++i) {
      cout << deleted_keys[i];
      if (i < n - 1) cout << ",";
    }
    cout << endl;
  }

  if (!changed_value_keys.empty()) {
    cout << "*";
    int n = int(changed_value_keys.size());
    for (int i = 0; i < n; ++i) {
      cout << changed_value_keys[i];
      if (i < n - 1) cout << ",";
    }
    cout << endl;
  }

  if (added_keys.empty() && deleted_keys.empty() &&
      changed_value_keys.empty()) {
    cout << "No changes" << endl;
  }

  cout << endl;
}

int main() {
  cin.tie(nullptr)->sync_with_stdio(false);
  int tc = 1;
  cin >> tc;
  while (tc--) solve();
}
