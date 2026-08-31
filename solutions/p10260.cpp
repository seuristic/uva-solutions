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
    str s;
    unordered_map<char, int> h;
    vector<str> l = {"BFPV", "CGJKQSXZ", "DT", "L", "MN", "R"};
    REP(i, 0, SZ(l) - 1) {
        FORE(c, l[i]) {
            h[c] = i + 1;
        }
    }
    while (cin >> s) {
        int prev = 0;
        FORE(c, s) {
            if (prev == h[c]) {
                continue;
            } else if (h[c] > 0) {
                cout << h[c];
            }
            prev = h[c];
        }
        cout << ENDL;
    }
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int tc = 1;
    // cin >> tc;
    while (tc--) solve();
}