#include <bits/stdc++.h>
using namespace std;

#define ALL(x) begin(x), end(x)
#define SZ(x) (int)(x).size()
#define REP(i, a, b) for (int i = (a); i <= (b); ++i)

using ll = long long;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int n, cases = 0;
    while (cin >> n && n) {
        vector<int> A(n), B(n), C(n), D(n);
        ll cycle = 1;

        REP(i, 0, n - 1) {
            cin >> A[i] >> B[i] >> C[i];
            D[i] = A[i] + B[i];
            cycle *= D[i];  // safe upper bound (as in reference code)
        }

        int answer = -1;

        REP(time, 1, cycle) {
            int awake = 0, sleep = 0;

            // count states at this minute
            REP(i, 0, n - 1) {
                if (C[i] <= A[i])
                    awake++;
                else
                    sleep++;
            }

            // termination condition
            if (awake == n) {
                answer = time;
                break;
            }

            // advance time by one minute
            REP(i, 0, n - 1) {
                C[i]++;

                // normal cycle completion
                if (C[i] == D[i] + 1) {
                    C[i] = 1;
                }
                // early wake-up: ONLY when attempting to enter sleep
                else if (C[i] == A[i] + 1 && awake >= sleep) {
                    C[i] = 1;
                }
            }
        }

        cout << "Case " << ++cases << ": " << answer << '\n';
    }

    return 0;
}
