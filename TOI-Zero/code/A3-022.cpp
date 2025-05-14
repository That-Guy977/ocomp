#include <iostream>
#include <algorithm>
#include <vector>
#define iter(c) c.begin(), c.end()

using namespace std;

int main() {
  int n;
  cin >> n;
  vector<bool> lit(360, 0);
  for (int i = 0; i < n; i++) {
    int a, b;
    cin >> a >> b;
    for (int x = a; x != b; x++, x %= 360) {
      lit[x] = true;
    }
  }
  int s = distance(lit.begin(), find(iter(lit), false));
  int mxr = 0;
  int curr = 0;
  for (int i = 0; i < 360; i++) {
  if (lit[(i + s) % 360]) {
      curr++;
      if (curr > mxr) mxr = curr;
    } else {
      curr = 0;
    }
  }
  cout << mxr << endl;
  return 0;
}
