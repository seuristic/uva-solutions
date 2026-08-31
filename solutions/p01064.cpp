#include <bits/stdc++.h>
using namespace std;

struct Packet {
  int msg, l, r;
};

int main() {
  ios::sync_with_stdio(false);
  cin.tie(nullptr);

  int N, M;
  int tc = 1;

  while (cin >> N >> M, N || M) {
    vector<int> sz(N + 1);
    for (int i = 1; i <= N; i++) cin >> sz[i];

    vector<Packet> packets(M);
    for (int i = 0; i < M; i++)
      cin >> packets[i].msg >> packets[i].l >> packets[i].r;

    vector<int> order(N);
    iota(order.begin(), order.end(), 1);

    int ans = INT_MAX;

    do {
      vector<int> expect(N + 1, 1);
      vector<map<int, int>> buffer(N + 1);

      int current = 0;
      int curBuf = 0;
      int mxBuf = 0;

      auto flush = [&](int id) {
        while (true) {
          auto it = buffer[id].find(expect[id]);
          if (it == buffer[id].end()) break;
          curBuf -= it->second - it->first + 1;
          expect[id] = it->second + 1;
          buffer[id].erase(it);
        }
      };

      for (auto& p : packets) {
        int active = order[current];

        while (current < N && expect[active] > sz[active]) {
          current++;
          if (current < N) flush(active);
        }

        if (current == N) break;

        if (p.msg != active) {
          buffer[p.msg][p.l] = p.r;
          curBuf += p.r - p.l + 1;
          mxBuf = max(mxBuf, curBuf);
        } else {
          if (p.l == expect[p.msg]) {
            expect[p.msg] = p.r + 1;
            flush(p.msg);
          } else {
            buffer[p.msg][p.l] = p.r;
            curBuf += p.r - p.l + 1;
            mxBuf = max(mxBuf, curBuf);
          }
        }
      }

      ans = min(ans, mxBuf);
    } while (next_permutation(order.begin(), order.end()));

    cout << "Case " << tc++ << ": " << ans << "\n\n";
  }

  return 0;
}
