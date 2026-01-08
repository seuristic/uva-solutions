#include <bits/stdc++.h>
using namespace std;

#define F first
#define S second
#define PB push_back
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
    int n;
    while (cin >> n) {
        int b = 1 << n;
        vector<ll> a(b);
        REP(i, 0, b - 1) {
            cin >> a[i];
        }
        vector<ll> p(b);
        REP(i, 0, b - 1) {
            REP(j, 0, n - 1) {
                p[i] += a[i ^ (1 << j)];
            }
        }
        ll result = 0;
        REP(i, 0, b - 1) {
            REP(j, 0, n - 1) {
                result = max(result, p[i] + p[i ^ (1 << j)]);
            }
        }
        cout << result << ENDL;
    }
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int tc = 1;
    // cin >> tc;
    while (tc--) solve();
}