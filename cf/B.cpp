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
  set<long, function<bool(long, long)>> res_mn([&res](long a, long b) {
    return res[a] != res[b] ? res[a] < res[b] : a < b;
  });
  for (int i = n - 1; i >= 0; i--) {
    int mn = 0;
    for (int j : res_mn) {
      if (mn && res[j] > mn) break;
      long cost = res[j] + a[j] * b[i];
      if (!mn || cost < mn) mn = cost;
    }
    res[i] = mn;
    res_mn.insert(i);
  }
  cout << res[0] << endl;
  return 0;
}
