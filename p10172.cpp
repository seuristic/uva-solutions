#include <bits/stdc++.h>
using namespace std;

void solve() {
    int n, s, q;
    cin >> n >> s >> q;

    vector<queue<int>> station(n);
    for (int i = 0; i < n; ++i) {
        int m;
        cin >> m;
        while (m--) {
            int x;
            cin >> x;
            station[i].push(x - 1);  // zero-based destination
        }
    }

    stack<int> carrier;
    int time = 0;
    int cur = 0;

    auto all_empty = [&]() {
        for (int i = 0; i < n; ++i)
            if (!station[i].empty())
                return false;
        return true;
    };

    while (true) {
        // 1. Unload phase
        while (!carrier.empty()) {
            if (carrier.top() == cur) {
                carrier.pop();
                time += 1;
            } else if ((int)station[cur].size() < q) {
                station[cur].push(carrier.top());
                carrier.pop();
                time += 1;
            } else {
                break;
            }
        }

        // 2. Load phase
        while ((int)carrier.size() < s && !station[cur].empty()) {
            carrier.push(station[cur].front());
            station[cur].pop();
            time += 1;
        }

        // 3. Termination check
        if (carrier.empty() && all_empty())
            break;

        // 4. Move to next station
        cur = (cur + 1) % n;
        time += 2;
    }

    cout << time << '\n';
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int tc;
    cin >> tc;
    while (tc--) {
        solve();
    }
    return 0;
}
