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
    int n;
    cin >> n;
    vector<string> a(n);
    for (string& s : a) {
        cin >> s;
    }

    vector<string> result(n);
    int count = 0, start = -1;
    for (int i = 0; i < n; ++i) {
        if (a[i][0] == '?') {
            ++count;
            if (start == -1) start = i;
        } else {
            result[i] = a[i];
            if (count > 0) {
                if ((count & 1) && start > 0) {
                    result[start + count / 2] = "middle of " + a[start - 1] + " and " + a[i];
                }
                if (start == 0) {
                    for (int j = count - 1; j >= 0; --j) {
                        result[start + j] += "left of " + result[start + j + 1];
                    }
                } else {
                    for (int j = 0; j < count / 2; ++j) {
                        result[start + j] += "right of " + result[start + j - 1];
                    }
                    for (int j = count - 1; j >= count / 2 + (count % 2); --j) {
                        result[start + j] += "left of " + result[start + j + 1];
                    }
                }
                count = 0;
                start = -1;
            }
        }
    }

    if (count > 0) {
        if (count > 0) {
            for (int j = 0; j < count; ++j) {
                result[start + j] += "right of " + result[start + j - 1];
            }
        }
    }

    int q;
    cin >> q;
    while (q--) {
        int index;
        cin >> index;
        cout << result[index - 1] << ENDL;
    }
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int tc = 1;
    // cin >> tc;
    while (tc--) solve();
}