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

const vi angles = {90, 180, 270};

int n;
vector<str> original, transformed;

vector<str> rotate(vector<str>& original, int angle) {
    vector<str> t = original;
    if (angle > 0) {
        REP(i, 0, n - 1) {
            REP(j, 0, n - 1) {
                if (angle == 90) {
                    t[j][n - i - 1] = original[i][j];
                } else if (angle == 180) {
                    t[n - i - 1][n - j - 1] = original[i][j];
                } else if (angle == 270) {
                    t[n - j - 1][i] = original[i][j];
                }
            }
        }
    }
    return t;
}

vector<str> reflect(vector<str>& x) {
    vector<str> t = x;
    REP(i, 0, n / 2 - 1) {
        REP(j, 0, n - 1) {
            swap(t[i][j], t[n - i - 1][j]);
        }
    }
    return t;
}

bool same(vector<str> t) {
    REP(i, 0, n - 1) {
        if (t[i] != transformed[i]) {
            return false;
        }
    }
    return true;
}

void solve() {
    int cnt = 0;
    while (cin >> n) {
        ++cnt;
        original.assign(n, str(n, ' '));
        transformed.assign(n, str(n, ' '));
        REP(i, 0, n - 1) {
            cin >> original[i] >> transformed[i];
        }

        cout << "Pattern " << cnt << " was ";

        if (same(original)) {
            cout << "preserved." << ENDL;
            continue;
        }

        bool found = false;
        REP(i, 0, SZ(angles) - 1) {
            if (same(rotate(original, angles[i]))) {
                cout << "rotated " << angles[i] << " degrees." << ENDL;
                found = true;
                break;
            }
        }

        if (found) continue;

        auto t = reflect(original);
        if (same(t)) {
            cout << "reflected vertically." << ENDL;
            continue;
        }

        REP(i, 0, SZ(angles) - 1) {
            if (same(rotate(t, angles[i]))) {
                cout << "reflected vertically and rotated " << angles[i] << " degrees." << ENDL;
                found = true;
                break;
            }
        }

        if (!found) {
            cout << "improperly transformed." << ENDL;
        }
    }
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int tc = 1;
    // cin >> tc;
    while (tc--) solve();
}