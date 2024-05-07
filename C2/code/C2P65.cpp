#include <iostream>
#include <cmath>

using namespace std;

void place(int, int[], int, int, int, int = 0, int = 0);
int quadrant(int, int, int);
int pow2(int);

int main() {
  int n;
  cin >> n;
  int x, y;
  char _;
  cin >> _ >> y >> _ >> x;
  x--;
  y--;
  int size = pow2(n);
  int board[size * size];
  for (int i = 0; i < size; i++) {
    for (int j = 0; j < size; j++) {
      board[i * size + j] = 0;
    }
  }
  place(n, board, n, x, y);
  for (int i = 0; i < size; i++) {
    for (int j = 0; j < size; j++) {
      cout << board[i * size + j];
    }
    cout << endl;
  }
  return 0;
}

void place(int n, int board[], int step, int x, int y, int offsetX, int offsetY) {
  int size = pow2(n);
  int half = pow2(step - 1);
  int q = quadrant(step, x, y);
  for (int i = 0; i < 2; i++) {
    for (int j = 0; j < 2; j++) {
      int currq = (!i * 2 | !j);
      if (step > 1) {
        if (q == currq) {
          place(
            n, board, step - 1,
            x % half,
            y % half,
            offsetX + (half * j),
            offsetY + (half * i)
          );
        } else {
          place(
            n, board, step - 1,
            (currq & 1 ? half - 1 : 0),
            (currq & 2 ? half - 1 : 0),
            offsetX + (half * j),
            offsetY + (half * i)
          );
        }
      }
      if (q != currq) {
        board[(i + offsetY + half - 1) * size + j + offsetX + half - 1] = q + 1;
      }
    }
  }
}

int quadrant(int step, int x, int y) {
  int half = pow2(step - 1);
  return ((x < half) | (y < half) * 2);
}

int pow2(int x) {
  return pow(2, x);
}
