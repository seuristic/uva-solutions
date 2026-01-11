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

str s;

void solve() {
    getline(cin, s);
    vector<char> st;
    FORE(x, s) {
        if (x == '(' || x == '[') {
            st.push_back(x);
        } else if (st.empty() || (st.back() == '(' && x == ']') || (st.back() == '[' && x == ')')) {
            cout << "No" << ENDL;
            return;
        } else {
            st.pop_back();
        }
    }

    cout << (st.empty() ? "Yes" : "No") << ENDL;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int tc = 1;
    cin >> tc;
    getline(cin, s);
    while (tc--) solve();
}