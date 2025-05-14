#include <iostream>

using namespace std;

int main() {
  int n, m;
  cin >> n >> m;
  int k;
  cin >> k;
  int grid[n][m];
  for (int i = 0; i < n; i++) {
    for (int j = 0; j < m; j++) {
      grid[i][j] = 0;
    }
  }
  for (int i = 0; i < k; i++) {
    int y, x;
    cin >> y >> x;
    grid[y][x] = -1;
    for (int dy = -1; dy <= 1; dy++) {
      int yp = y + dy;
      if (yp < 0 || yp >= n) continue;
      for (int dx = -1; dx <= 1; dx++) {
        int xp = x + dx;
        if (xp < 0 || xp >= m) continue;
        if (grid[yp][xp] != -1) grid[yp][xp]++;
      }
    }
  }
  for (int i = 0; i < n; i++) {
    for (int j = 0; j < m; j++) {
      if (j) cout << " ";
      if (grid[i][j] != -1) {
        cout << grid[i][j];
      } else {
        cout << "x";
      }
    }
    cout << endl;
  }
  return 0;
}
