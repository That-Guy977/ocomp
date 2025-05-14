#include <iostream>

using namespace std;

int main() {
  int x[5][5];
  for (int i = 0; i < 5; i++) {
    for (int j = 0; j < 5; j++) {
      cin >> x[i][j];
    }
  }
  int r = -1;
  int c = -1;
  for (int i = 0; i < 5; i++) {
    int rs = 0;
    int cs = 0;
    for (int j = 0; j < 5; j++) {
      rs += x[i][j];
      cs += x[j][i];
    }
    if (rs % 2 != 0) r = i;
    if (cs % 2 != 0) c = i;
  }
  cout << r << " " << c << endl;
  return 0;
}
