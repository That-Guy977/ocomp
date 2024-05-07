#include <iostream>

using namespace std;

int moveX[] { +1, +1, -1, -1, +2, +2, -2, -2 };
int moveY[] { +2, -2, +2, -2, +1, -1, +1, -1 };

int paths(int, int, int, int, bool[], int);
bool valid(int, int, int, int);

int main() {
  int m, n, x, y;
  cin >> m >> n >> x >> y;
  bool grid[m * n];
  for (int i = 0; i < m; i++) {
    for (int j = 0; j < n; j++) {
      grid[i * n + j] = 0;
    }
  }
  grid[x * n + y] = 1;
  cout << paths(m, n, x, y, grid, 1) << endl;
  return 0;
}

int paths(int m, int n, int x, int y, bool visited[], int count) {
  if (count == m * n) return 1;
  int res = 0;
  for (int i = 0; i < 8; i++) {
    int nextX = x + moveX[i];
    int nextY = y + moveY[i];
    if (valid(m, n, nextX, nextY) && !visited[nextX * n + nextY]) {
      visited[nextX * n + nextY] = true;
      res += paths(m, n, nextX, nextY, visited, count + 1);
      visited[nextX * n + nextY] = false;
    }
  }
  return res;
}

bool valid(int m, int n, int x, int y) {
  return x >= 0 && x < m && y >= 0 && y < n;
}
