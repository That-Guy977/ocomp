#include <iostream>
#include <tuple>

using namespace std;

int main() {
  int m, n, b;
  cin >> m >> n >> b;
  int board[m][n];
  for (int i = 0; i < m; i++) {
    for (int j = 0; j < n; j++) {
      board[i][j] = 0;
    }
  }
  for (int bi = 0; bi < b; bi++) {
    int y, x, s;
    cin >> y >> x >> s;
    y--;
    x--;
    for (int i = 0; i < s; i++) {
      for (int j = 0; j < s; j++) {
        board[i + y][j + x] = -1;
      }
    }
    for (int k = -1; k < s; k++) {
      pair<int, int> pos[] = {
        { y + k, x - 1 },
        { y + s, x + k },
        { y + s - k - 1, x + s },
        { y - 1, x + s - k - 1 }
      };
      for (auto [i, j] : pos) {
        if (i >= 0 && i < m && j >= 0 && j < n && board[i][j] != -1) {
          board[i][j]++;
        }
      }
    }
  }
  for (int i = 0; i < m; i++) {
    for (int j = 0; j < n; j++) {
      if (board[i][j] != -1) {
        cout << board[i][j];
      } else {
        cout << "*";
      }
    }
    cout << endl;
  }
  return 0;
}
