#include <bits/stdc++.h>
using namespace std;

using ll = long long;

ll convertToUnits(ll amount) {
  int units = 0;

  if (amount <= 2 * 100) return amount / 2;

  units = 100;
  amount -= 2 * 100;

  if (amount <= 3 * 9900) return units + amount / 3;

  units = 10000;
  amount -= 3 * 9900;

  if (amount <= 5 * 990000) return units + amount / 5;

  units = 1000000;
  amount -= 5 * 990000;

  return units + amount / 7;
}

ll convertToAmount(ll units) {
  ll amount = 0;

  if (units <= 100) return 2 * units;

  amount += 2 * 100;

  if (units <= 10000) return amount + 3 * (units - 100);

  amount += 3 * 9900;

  if (units <= 1000000) return amount + 5 * (units - 10000);

  amount += 5 * 990000;

  return amount + 7 * (units - 1000000);
}

void solve() {
  ll a, b;
  while (cin >> a >> b, a || b) {
    ll total = convertToUnits(a);
    ll low = 1, high = total;
    while (low < high) {
      ll mid = low + (high - low) / 2;
      ll amount = convertToAmount(mid);
      ll amount2 = convertToAmount(total - mid);
      if (amount2 - amount > b) {
        low = mid + 1;
      } else {
        high = mid;
      }
    }
    cout << convertToAmount(low) << '\n';
  }
}

int main() {
  ios::sync_with_stdio(false);
  cin.tie(nullptr);

  int tc = 1;
  // cin >> tc;
  while (tc--) solve();

  return 0;
}
