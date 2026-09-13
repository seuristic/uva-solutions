#include <bits/stdc++.h>
using namespace std;

const int dir[] = {0, -1, 0, 1, 0};

const vector<string> bits = {
    "0000",
    "0001",
    "0010",
    "0011",
    "0100",
    "0101",
    "0110",
    "0111",
    "1000",
    "1001",
    "1010",
    "1011",
    "1100",
    "1101",
    "1110",
    "1111"
};

unordered_map<int, char> cc_to_char = {
    {0, 'W'}, {1, 'A'}, {2, 'K'}, {3, 'J'}, {4, 'S'}, {5, 'D'}
};

int h, w;
vector<string> img;

void floodWhite(int r, int c) {
  img[r][c] = '.';

  for (int i = 0; i < 4; ++i) {
    int nr = r + dir[i];
    int nc = c + dir[i + 1];

    if (nr >= 0 && nr < h && nc >= 0 && nc < w && img[nr][nc] == '0') {
      floodWhite(nr, nc);
    }
  }
}

void floodHole(int r, int c) {
  img[r][c] = '.';

  for (int i = 0; i < 4; ++i) {
    int nr = r + dir[i];
    int nc = c + dir[i + 1];

    if (nr >= 0 && nr < h && nc >= 0 && nc < w && img[nr][nc] == '0') {
      floodHole(nr, nc);
    }
  }
}

int floodGlyph(int r, int c) {
  img[r][c] = '2';

  int holes = 0;

  for (int i = 0; i < 4; ++i) {
    int nr = r + dir[i];
    int nc = c + dir[i + 1];

    if (nr < 0 || nr >= h || nc < 0 || nc >= w) continue;

    if (img[nr][nc] == '1') holes += floodGlyph(nr, nc);
    else if (img[nr][nc] == '0') {
      ++holes;
      floodHole(nr, nc);
    }
  }

  return holes;
}

void solve() {
  int tc = 1;

  while (cin >> h >> w && (h || w)) {
    vector<string> original(h);

    for (int r = 0; r < h; ++r) {
      string line;
      cin >> line;

      for (char ch : line) {
        int val;

        if (isdigit(ch)) val = ch - '0';
        else val = ch - 'a' + 10;

        original[r] += bits[val];
      }
    }

    w *= 4;

    img.assign(h + 2, string(w + 2, '0'));

    for (int r = 0; r < h; ++r) {
      for (int c = 0; c < w; ++c) {
        img[r + 1][c + 1] = original[r][c];
      }
    }

    h += 2;
    w += 2;

    floodWhite(0, 0);

    string ans;

    for (int r = 0; r < h; ++r) {
      for (int c = 0; c < w; ++c) {
        if (img[r][c] == '1') {
          int holes = floodGlyph(r, c);
          ans += cc_to_char[holes];
        }
      }
    }

    sort(ans.begin(), ans.end());

    cout << "Case " << tc++ << ": " << ans << '\n';

    img.clear();
  }
}

int main() {
  ios::sync_with_stdio(false);
  cin.tie(nullptr);

  solve();

  return 0;
}
