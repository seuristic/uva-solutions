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
#include <sstream>
#include <stack>
#include <string>
#include <tuple>
#include <unordered_map>
#include <unordered_set>
#include <utility>
#include <vector>
using namespace std;

struct Contestant {
    int solved = 0;
    int penalty = 0;
    bool present = false;
    bool solved_p[10] = {};
    int wrong[10] = {};
};

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int T;
    cin >> T;
    string line;
    getline(cin, line);
    getline(cin, line);

    while (T--) {
        vector<Contestant> c(101);

        while (getline(cin, line) && !line.empty()) {
            stringstream ss(line);
            int cid, pid, time;
            char status;
            ss >> cid >> pid >> time >> status;

            c[cid].present = true;

            if (status == 'C' && !c[cid].solved_p[pid]) {
                c[cid].solved_p[pid] = true;
                c[cid].solved++;
                c[cid].penalty += time + c[cid].wrong[pid] * 20;
            } else if (status == 'I' && !c[cid].solved_p[pid]) {
                c[cid].wrong[pid]++;
            }
        }

        vector<int> ids;
        for (int i = 1; i <= 100; i++) {
            if (c[i].present) ids.push_back(i);
        }

        sort(ids.begin(), ids.end(), [&](int a, int b) {
            if (c[a].solved != c[b].solved)
                return c[a].solved > c[b].solved;
            if (c[a].penalty != c[b].penalty)
                return c[a].penalty < c[b].penalty;
            return a < b;
        });

        for (int id : ids) {
            cout << id << " " << c[id].solved << " " << c[id].penalty << "\n";
        }
        if (T) cout << "\n";
    }
}
