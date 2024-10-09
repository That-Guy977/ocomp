#include <iostream>

using namespace std;

struct order {
  int l, r, c;
};

int main() {
  int n, m;
  cin >> n >> m;
  order orders[m + 1];
  for (int i = 0; i < m; i++) {
    int l, r, c;
    cin >> l >> r >> c;
    orders[m - i - 1] = { l, r, c };
  }
  orders[m] = { 1, n, 0 };
  for (int i = 1; i <= n; i++) {
    for (int j = 0; j <= m; j++) {
      if (i >= orders[j].l && i <= orders[j].r) {
        cout << orders[j].c << " ";
        break;
      }
    }
  }
  cout << endl;
  return 0;
}
