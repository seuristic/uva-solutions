#include <algorithm>
#include <bitset>
#include <cmath>
#include <deque>
#include <functional>
#include <iomanip>
#include <iostream>
#include <limits>
#include <map>
#include <numeric>
#include <queue>
#include <set>
#include <stack>
#include <string>
#include <tuple>
#include <unordered_map>
#include <unordered_set>
#include <utility>
#include <vector>

#define F first
#define S second
#define PB push_back
#define ALL(x) begin(x), end(x)
#define SZ(x) (int)(x).size()
#define REP(i, a, b) for (int i = (a); i <= (b); i++)

using namespace std;
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
    int n, m;
    while (cin >> n >> m && n && m) {
        vector<str> big(n), small(m);
        REP(i, 0, n - 1)
        cin >> big[i];
        REP(i, 0, m - 1)
        cin >> small[i];

        vii relPos;
        bool foundOrigin = false;
        ii origin;
        REP(i, 0, m - 1) {
            REP(j, 0, m - 1) {
                if (small[i][j] == '*') {
                    if (!foundOrigin) {
                        foundOrigin = true;
                        origin = {i, j};
                    }
                    relPos.PB({i - origin.F, j - origin.S});
                }
            }
        }

        bool ok = true;
        REP(i, 0, n - 1) {
            REP(j, 0, n - 1) {
                if (big[i][j] == '*') {
                    for (auto& pos : relPos) {
                        int r = i + pos.F;
                        int c = j + pos.S;
                        if (r < 0 || r >= n || c < 0 || c >= n || big[r][c] != '*') {
                            ok = false;
                            break;
                        }
                        big[r][c] = '.';
                    }
                }
            }
            if (!ok) break;
        }

        REP(i, 0, n - 1) {
            REP(j, 0, n - 1) {
                if (big[i][j] == '*') {
                    ok = false;
                    break;
                }
            }
            if (!ok) break;
        }

        cout << (ok ? 1 : 0) << ENDL;
    }
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int tc = 1;
    // cin >> tc;
    while (tc--) solve();
}