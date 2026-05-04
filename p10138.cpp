#include <bits/stdc++.h>
using namespace std;

struct Event {
  int month, day, hour, min;
  bool isEntry;
  long long dist;

  int getTime() const {
    return min + hour * 60 + day * 24 * 60 + month * 30 * 24 * 60;
  }

  bool operator<(const Event& other) const {
    return getTime() < other.getTime();
  }
};

void solve() {
  vector<int> fares(24);
  for (int& f : fares) {
    cin >> f;
  }

  map<string, vector<Event>> events;

  cin.ignore();
  string line;

  while (getline(cin, line) && !line.empty()) {
    stringstream ss(line);
    string plate, status;
    Event e;
    char ignore;
    ss >> plate >> e.month >> ignore >> e.day >> ignore >> e.hour >> ignore >>
        e.min >> status >> e.dist;
    e.isEntry = status == "enter";
    events[plate].push_back(e);
  }

  map<string, long long> vehicle_bills;
  for (auto& [plate, events] : events) {
    int n = int(events.size());
    sort(events.begin(), events.end());
    long long bill = 200;
    for (int i = 0; i < n - 1; ++i) {
      auto enter_event = events[i];
      auto exit_event = events[i + 1];
      if (enter_event.isEntry && !exit_event.isEntry) {
        int net_dist = abs(exit_event.dist - enter_event.dist);
        bill += net_dist * fares[enter_event.hour];
        bill += 100;
        ++i;
      }
    }
    if (bill != 200) {
      cout << plate << " $" << fixed << setprecision(2) << bill / 100.0 << endl;
    }
  }
}

int main() {
  cin.tie(nullptr)->sync_with_stdio(false);
  int tc = 1;
  cin >> tc;
  while (tc--) {
    solve();
    if (tc) cout << endl;
  }
}
