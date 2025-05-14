#include <iostream>

using namespace std;

int main() {
  int n, m;
  cin >> n >> m;
  char grid[n][m];
  for (int i = 0; i < n; i++) {
    for (int j = 0; j < m; j++) {
      cin >> grid[i][j];
    }
  }
  for (int i = n - 1; i > 0; i--) {
    for (int j = 0; j < m; j++) {
      if (grid[i - 1][j] == '*') {
        grid[i][j] = '*';
      }
    }
  }
  for (int i = 0; i < n; i++) {
    for (int j = 0; j < m; j++) {
      if (j) cout << " ";
      cout << grid[i][j];
    }
    cout << endl;
  }
  return 0;
}
