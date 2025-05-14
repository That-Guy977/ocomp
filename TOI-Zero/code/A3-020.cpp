#include <iostream>
#include <algorithm>

using namespace std;

int main() {
  int h1, h2, b1, b2, x, y;
  cin >> h1 >> h2 >> b1 >> b2;
  cin >> x >> y;
  int mx = 0;
  for (int k1 = 0; k1 <= min(h1, b1); k1++) {
    for (int k2 = 0; k2 <= min(h2, b2); k2++) {
      int l1 = min(h1 - k1, b2 - k2);
      int l2 = min(h2 - k2, b1 - k1);
      int res = min(k1 + k2, x) + min(l1 + l2, y);
      if (res > mx) mx = res;
    }
  }
  cout << mx << endl;
  return 0;
}
