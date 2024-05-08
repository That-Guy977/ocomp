#include <iostream>
#include <functional>
#include <set>

using namespace std;

int main() {
  int n;
  cin >> n;
  int a[n], b[n];
  for (int i = 0; i < n; i++) {
    cin >> a[i];
  }
  for (int i = 0; i < n; i++) {
    cin >> b[i];
  }
  long res[n];
  for (int i = n - 1; i >= 0; i--) {
    int mn = 0;
    for (int j = i + 1; j < n; j++) {
      long cost = res[j] + a[j] * b[i];
      if (!mn || cost < mn) mn = cost;
    }
    res[i] = mn;
  }
  cout << res[0] << endl;
  return 0;
}
