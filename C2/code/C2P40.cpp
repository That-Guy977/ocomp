#include <iostream>

using namespace std;

int moveX[] { +1, -1,  0,  0 };
int moveY[] {  0,  0, +1, -1 };

struct path {
  int count, mx, mn;
};

path paths(int, int, int, int, bool[]);
bool valid(int, int, int, int);

int main() {
  int m, n;
  cin >> m >> n;
  bool grid[m * n];
  for (int i = 0; i < m; i++) {
    for (int j = 0; j < n; j++) {
      char c;
      cin >> c;
      grid[i * n + j] = c == 'x';
    }
  }
  grid[0] = 1;
  path res = paths(m, n, 0, 0, grid);
  cout << res.count << " " << res.mx << " " << res.mn << endl;
  return 0;
}

path paths(int m, int n, int x, int y, bool grid[]) {
  if (x == m - 1 && y == n - 1) return { 1, 1, 1 };
  path res = { 0, -1, -1 };
  for (int i = 0; i < 4; i++) {
    int nextX = x + moveX[i];
    int nextY = y + moveY[i];
    if (valid(m, n, nextX, nextY) && !grid[nextX * n + nextY]) {
      grid[nextX * n + nextY] = true;
      path subres = paths(m, n, nextX, nextY, grid);
      res.count += subres.count;
      if (subres.mx != -1 && (res.mx == -1 || subres.mx > res.mx)) res.mx = subres.mx;
      if (subres.mn != -1 && (res.mn == -1 || subres.mn < res.mn)) res.mn = subres.mn;
      grid[nextX * n + nextY] = false;
    }
  }
  if (res.count) {
    res.mx++;
    res.mn++;
  }
  return res;
}

bool valid(int m, int n, int x, int y) {
  return x >= 0 && x < m && y >= 0 && y < n;
}
