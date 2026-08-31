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
    str a;
    cin >> a;
    str s = "";
    int m = SZ(a);
    int left = (m - 1) / 2, right = m / 2;
    ll result = 0;
    while (left >= 0 || right < m) {
        result <<= 1;
        int len = left + 1 + (m - right) - (left == right);
        if (len & 1) {
            if (left + 1 > m - right) {
                result += a[left] - '0';
                --left;
            } else if (left + 1 < m - right) {
                result += a[right] - '0';
                ++right;
            } else {
                result += a[left] - '0';
                --left;
                ++right;
            }
        } else {
            if (a[left] < a[right]) {
                result += a[right] - '0';
                ++right;
            } else {
                result += a[left] - '0';
                --left;
            }
        }

        result %= MOD;
    }

    cout << result << ENDL;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int tc = 1;
    cin >> tc;
    REP(i, 1, tc) {
        cout << "Case #" << i << ": ";
        solve();
    }
}