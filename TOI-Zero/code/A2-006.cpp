#include <iostream>

using namespace std;

int walk(bool[], int, int, int);

int main() {
  int n;
  cin >> n;
  bool grid[n * n];
  for (int i = 0; i < n; i++) {
    for (int j = 0; j < n; j++) {
      char cell;
      cin >> cell;
      grid[i * n + j] = cell == '.';
    }
  }
  cout << walk(grid, n, n - 1, n - 1) << endl;
  return 0;
}

int walk(bool grid[], int n, int i, int j) {
  if (!grid[i * n + j]) return 0;
  grid[i * n + j] = false;
  int res = 1;
  if (i > 0) {
    res += walk(grid, n, i - 1, j);
  }
  if (j > 0) {
    res += walk(grid, n, i, j - 1);
  }
  return res;
}
