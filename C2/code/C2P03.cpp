#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;

int main() {
  vector<int> warehouse;
  int n, t;
  cin >> n >> t;
  for (int i = 0; i < n; i++) {
    int h;
    cin >> h;
    warehouse.push_back(h);
  }
  for (int i = 0; i < t; i++) {
    int op, x, y;
    cin >> op;
    switch (op) {
      case 1:
        cin >> x >> y;
        if (warehouse[x - 1] < y) {
          warehouse[x - 1]++;
        }
        break;
      case 2:
        cin >> x >> y;
        if (warehouse[x - 1] >= y) {
          warehouse[x - 1]--;
        }
        break;
      case 3:
        cin >> x >> y;
        for (int j = x - 2; j <= x; j++) {
          warehouse[j] -= min(max(warehouse[j] - y + 2, 0), min(3, warehouse[j]));
        }
        break;
      case 4:
        cin >> y;
        for (int j = 0; j < n; j++) {
          if (warehouse[j] >= y) {
            warehouse[j]--;
          }
        }
        break;
    }
    for (int j = 0; j < n; j++) {
      if (j) cout << " ";
      cout << warehouse[j];
    }
    cout << endl;
  }
  return 0;
}
