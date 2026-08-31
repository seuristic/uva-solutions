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

#define F first
#define S second
#define PB push_back
#define ALL(x) begin(x), end(x)
#define RALL(x) rbegin(x), rend(x)
#define SZ(x) (int)(x).size()
#define REP(i, a, b) for (int i = (a); i <= (b); ++i)
#define PER(i, a, b) for (int i = (a); i >= (b); --i)

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

ll ans = 0;

void merge(vi& a, int left, int mid, int right) {
    int n1 = mid - left + 1;
    int n2 = right - mid;
    vi L(n1), R(n2);
    REP(i, 0, n1 - 1) {
        L[i] = a[left + i];
    }
    REP(i, 0, n2 - 1) {
        R[i] = a[mid + i + 1];
    }
    int i = 0, j = 0, k = left;
    while (i < n1 && j < n2) {
        if (L[i] <= R[j]) {
            a[k] = L[i];
            ++i;
        } else {
            ans += n1 - i;
            a[k] = R[j];
            ++j;
        }
        ++k;
    }

    while (i < n1) {
        a[k] = L[i];
        ++i, ++k;
    }

    while (j < n2) {
        a[k] = R[j];
        ++j, ++k;
    }
}

void mergeSort(vi& a, int left, int right) {
    if (left >= right) return;
    int mid = left + (right - left) / 2;
    mergeSort(a, left, mid);
    mergeSort(a, mid + 1, right);
    merge(a, left, mid, right);
}

void solve() {
    int n;
    while (cin >> n && n) {
        vi a(n);
        REP(i, 0, n - 1) {
            cin >> a[i];
        }

        ans = 0;
        mergeSort(a, 0, n - 1);

        cout << ans << ENDL;
    }
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int tc = 1;
    // cin >> tc;
    while (tc--) solve();
}