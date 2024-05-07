#include <iostream>
#include <queue>
#include <string>

using namespace std;

void place(int, int[], queue<char>&, int, int, int = 0, int = 0);

int main() {
  int n, m;
  cin >> n >> m;
  string raw;
  cin >> raw;
  int board[n * m];
  for (int i = 0; i < n; i++) {
    for (int j = 0; j < m; j++) {
      board[i * m + j] = 0;
    }
  }
  queue<char> code;
  for (char ch : raw) {
    code.push(ch);
  }
  place(m, board, code, n, m);
  for (int i = 0; i < n; i++) {
    for (int j = 0; j < m; j++) {
      cout << board[i * m + j];
    }
    cout << endl;
  }
  return 0;
}

void place(int m, int board[], queue<char> &code, int h, int w, int offsetX, int offsetY) {
  if (!h || !w) return;
  if (code.front() == 'D') {
    code.pop();
    int halfu = (h + 1) / 2;
    int halfd = h / 2;
    int halfl = (w + 1) / 2;
    int halfr = w / 2;
    place(m, board, code, halfu, halfl, offsetX, offsetY);
    place(m, board, code, halfu, halfr, offsetX + halfl, offsetY);
    place(m, board, code, halfd, halfl, offsetX, offsetY + halfu);
    place(m, board, code, halfd, halfr, offsetX + halfl, offsetY + halfu);
  } else {
    for (int i = 0; i < h; i++) {
      for (int j = 0; j < w; j++) {
        board[(i + offsetY) * m + j + offsetX] = code.front() - 48;
      }
    }
    code.pop();
  }
}
