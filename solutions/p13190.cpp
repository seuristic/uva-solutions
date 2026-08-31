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
    str name;
    int priority, duration;
    int time;
    bool operator>(const Node& other) const {
        if (time == other.time) return priority > other.priority;
        return time > other.time;
    }
};

void solve() {
    int n, k;
    cin >> n >> k;
    priority_queue<Node, vector<Node>, greater<Node>> pq;
    REP(i, 0, n - 1) {
        Node node;
        cin >> node.name >> node.duration;
        node.priority = i;
        node.time = node.duration;
        pq.push(node);
    }

    while (k--) {
        Node node = pq.top();
        pq.pop();
        cout << node.time << ' ' << node.name << ENDL;
        node.time += node.duration;
        pq.push(node);
    }
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int tc = 1;
    cin >> tc;
    while (tc--) solve();
}