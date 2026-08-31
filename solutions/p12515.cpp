#include <bits/stdc++.h>
using namespace std;

void solve() {
  int m, q;
  cin >> m >> q;
  vector<string> sign(m);
  for (int i = 0; i < m; ++i) {
    cin >> sign[i];
  }

  while (q--) {
    string clip;
    cin >> clip;
    int clip_size = clip.size();
    int simi = -1, pos = -1;
    for (int i = 0; i < m; ++i) {
      int sign_size = sign[i].size();
      for (int step = 0; step + clip_size <= sign_size; ++step) {
        int match = 0;
        for (int j = 0; j < clip_size; ++j) {
          int k = j + step;
          if (0 <= k && k < sign_size && sign[i][k] == clip[j]) {
            ++match;
          }
        }
        if (simi < match) {
          simi = match;
          pos = i + 1;
        }
      }
    }

    cout << pos << '\n';
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
