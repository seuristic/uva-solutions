#include <algorithm>
#include <bitset>
#include <climits>
#include <cmath>
#include <deque>
#include <iostream>
#include <map>
#include <queue>
#include <set>
#include <stack>
#include <string>
#include <tuple>
#include <utility>
#include <vector>

#define F first
#define S second
#define PB push_back
#define ALL(x) begin(x), end(x)
#define SIZE(x) (int)(x).size()

using namespace std;
using ll = long long;
using vi = vector<int>;
using pii = pair<int, int>;

constexpr char ENDL = '\n';
constexpr double EPS = 1e-9;
constexpr int MOD = 1e9 + 7;
constexpr ll INF = 1e18;

void solve() {
    vi a[3];
    for (int i = 0; i < 3; ++i) {
        int n;
        cin >> n;
        a[i].assign(n, 0);
        for (int& x : a[i]) {
            cin >> x;
        }
    }

    vi result[3];
    int max_len = 0;
    for (int i = 0; i < 3; ++i) {
        for (int x : a[i]) {
            bool found = false;
            for (int j = 0; j < 2 && !found; ++j) {
                for (int y : a[(i + j + 1) % 3]) {
                    if (x == y) {
                        found = true;
                        break;
                    }
                }
            }
            if (!found) {
                result[i].PB(x);
                max_len = max(max_len, SIZE(result[i]));
            }
        }
    }

    for (int i = 0; i < 3; ++i) {
        if (SIZE(result[i]) == max_len) {
            sort(ALL(result[i]));

            cout << (i + 1) << " " << max_len;
            for (int j = 0; j < SIZE(result[i]); ++j) {
                cout << " " << result[i][j];
            }
            cout << ENDL;
        }
    }
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int tc = 1;
    cin >> tc;
    for (int i = 0; i < tc; ++i) {
        cout << "Case #" << i + 1 << ":\n";
        solve();
    }
}