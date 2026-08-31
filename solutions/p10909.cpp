#include <bits/stdc++.h>
using namespace std;

#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>
using namespace __gnu_pbds;
template <typename T>
using ordered_set =
    tree<T, null_type, less<T>, rb_tree_tag, tree_order_statistics_node_update>;

const int MAX = 2000000;
ordered_set<int> os;
vector<int> lucky;

void precompute() {
  for (int i = 1; i <= MAX; i += 2) {
    os.insert(i);
  }

  int index = 1;
  while (true) {
    if (index >= int(os.size())) break;

    int step = *os.find_by_order(index);
    if (step >= int(os.size())) break;

    vector<int> to_remove;
    for (int i = step - 1; i < int(os.size()); i += step) {
      to_remove.push_back(*os.find_by_order(i));
    }

    for (int& x : to_remove) {
      os.erase(x);
    }

    ++index;
  }

  for (auto x : os) {
    lucky.push_back(x);
  }
}

void solve() {
  int n;
  while (cin >> n && n) {
    if (n % 2 != 0) {
      cout << n << " is not the sum of two luckies!" << '\n';
      continue;
    }

    bool found = false;
    int index =
        upper_bound(lucky.begin(), lucky.end(), n / 2) - lucky.begin() - 1;
    for (int i = index; i >= 0; --i) {
      int a = lucky[i];
      int b = n - a;
      if (binary_search(lucky.begin(), lucky.end(), b)) {
        cout << n << " is the sum of " << a << " and " << b << "." << '\n';
        found = true;
        break;
      }
    }

    if (!found) {
      cout << n << " is not the sum of two luckies!" << '\n';
    }
  }
}

int main() {
  cin.tie(nullptr)->sync_with_stdio(false);

  precompute();

  solve();
}
