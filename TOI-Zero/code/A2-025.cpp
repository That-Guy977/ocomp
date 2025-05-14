#include <iostream>
#include <algorithm>
#include <cmath>

using namespace std;

const int risk[] = { 100, 60, 20 };

int main() {
  int h, w;
  cin >> h >> w;
  int r, c;
  cin >> r >> c;
  int n;
  cin >> n;
  int grid[h][w];
  int safe = h * w;
  for (int i = 0; i < h; i++) {
    for (int j = 0; j < w; j++) {
      grid[i][j] = 0;
    }
  }
  for (int i = 0; i < n; i++) {
    int y, x;
    cin >> y >> x;
    for (int dy = -2; dy <= 2; dy++) {
      int yp = y + dy;
      if (yp < 0 || yp >= h) continue;
      for (int dx = -2; dx <= 2; dx++) {
        int xp = x + dx;
        if (xp < 0 || xp >= w) continue;
        int d = max(abs(dy), abs(dx));
        int c = risk[d];
        if (grid[yp][xp] == 0) safe--;
        if (c > grid[yp][xp]) grid[yp][xp] = c;
      }
    }
  }
  cout << safe << endl;
  cout << grid[r][c] << "%" << endl;
  return 0;
}
