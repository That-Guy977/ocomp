#include <iostream>
#include <vector>
#include <map>
#include <set>
#include <tuple>

using namespace std;

int main() {
  int n;
  cin >> n;
  long plots[n][n];
  cin >> plots[0][0];
  for (int j = 1; j < n; j++) {
    cin >> plots[0][j];
    plots[0][j] += plots[0][j - 1];
  }
  for (int i = 1; i < n; i++) {
    cin >> plots[i][0];
    plots[i][0] += plots[i - 1][0];
    for (int j = 1; j < n; j++) {
      cin >> plots[i][j];
      plots[i][j] += plots[i][j - 1] + plots[i - 1][j] - plots[i - 1][j - 1];
    }
  }
  int q;
  cin >> q;
  for (int qi = 0; qi < q; qi++) {
    int i1, j1, i2, j2;
    cin >> i1 >> j1 >> i2 >> j2;
    long value = plots[i2][j2];
    if (i1) value -= plots[i1 - 1][j2];
    if (j1) value -= plots[i2][j1 - 1];
    if (i1 && j1) value += plots[i1 - 1][j1 - 1];
    cout << value << endl;
  }
  return 0;
}
