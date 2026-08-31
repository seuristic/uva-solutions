#include <bits/stdc++.h>
using namespace std;

#define ALL(x) begin(x), end(x)
#define RALL(x) rbegin(x), rend(x)
#define SZ(x) (int)(x).size()
#define REP(i, a, b) for (int i = (a); i <= (b); ++i)
#define PER(i, a, b) for (int i = (a); i >= (b); --i)
#define FORE(x, a) for (auto x : (a))

using ll = long long;
using vi = vector<int>;
using ii = pair<int, int>;
using vii = vector<ii>;
using str = string;

constexpr char ENDL = '\n';
constexpr double EPS = 1e-9;
constexpr int MOD = 1e9 + 7;
constexpr int INF = 1e9;
constexpr ll LLINF = 1e18;

void solve() {
    int cnt = 1;
    str s;
    while (cin >> s && s != "end") {
        vector<vector<char>> container;
        FORE(c, s) {
            if (container.empty()) {
                container.push_back({c});
                continue;
            }

            int mini = -1;
            REP(i, 0, SZ(container) - 1) {
                if (container[i].back() >= c) {
                    if (mini == -1 || container[mini].back() > container[i].back()) {
                        mini = i;
                    }
                }
            }

            if (mini == -1) {
                container.push_back({c});
            } else {
                container[mini].push_back(c);
            }
        }

        cout << "Case " << cnt++ << ": ";
        cout << SZ(container) << ENDL;
    }
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int tc = 1;
    // cin >> tc;
    while (tc--) solve();
}