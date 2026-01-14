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

struct Node {
    int sum;
    int i, j;
    bool operator>(const Node& other) const {
        return sum > other.sum;
    }
};

void solve() {
    int k;
    while (cin >> k) {
        vector<vi> a(k, vi(k));
        REP(i, 0, k - 1) {
            REP(j, 0, k - 1) {
                cin >> a[i][j];
            }
        }

        REP(i, 0, k - 1) {
            sort(ALL(a[i]));
        }

        REP(pos, 1, k - 1) {
            priority_queue<Node, vector<Node>, greater<Node>> pq;
            REP(i, 0, k - 1) {
                pq.push({a[pos - 1][i] + a[pos][0], i, 0});
            }

            vi next(k);
            REP(cnt, 0, k - 1) {
                auto [sum, i, j] = pq.top();
                pq.pop();
                next[cnt] = sum;
                if (j + 1 < k) {
                    pq.push({a[pos - 1][i] + a[pos][j + 1], i, j + 1});
                }
            }

            a[pos] = next;
        }

        REP(i, 0, k - 1) {
            cout << a[k - 1][i] << " \n"[i == k - 1];
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