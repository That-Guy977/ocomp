#include <iostream>
#include <set>

using namespace std;

int main() {
  int t;
  cin >> t;
  for (int ti = 0; ti < t; ti++) {
    int m, n;
    cin >> m >> n;
    int mxd = 0;
    int mxc = 0;
    for (int i = 0; i < m; i++) {
      int d, h;
      cin >> d >> h;
      if (d > mxd) mxd = d;
      if (d - h > mxc) mxc = d - h;
    }
    cout << (mxc ? (n - mxd + mxc - 1) / mxc + 1 : mxd >= n ? 1 : -1) << endl;
  }
  return 0;
}
