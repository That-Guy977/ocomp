#include <iostream>

using namespace std;

int main() {
  int w, l, m, n;
  cin >> w >> l >> m >> n;
  int mn = -1;
  for (int i = m; i <= n; i++) {
    int e = (w % i) * (l % i);
    if (mn == -1 || e < mn) mn = e;
  }
  cout << mn << endl;
  return 0;
}
