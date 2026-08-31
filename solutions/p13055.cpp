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
    int n;
    cin >> n;
    vector<str> st;
    str line;
    getline(cin, line);
    while (getline(cin, line)) {
        stringstream ss(line);
        if (line.substr(0, 5) == "Sleep" && SZ(line) > 6) {
            str sleep, person;
            ss >> sleep >> person;
            st.push_back(person);
        } else if (line == "Test") {
            if (st.empty()) {
                cout << "Not in a dream" << ENDL;
            } else {
                cout << st.back() << ENDL;
            }
        } else if (line == "Kick") {
            if (!st.empty()) {
                st.pop_back();
            }
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