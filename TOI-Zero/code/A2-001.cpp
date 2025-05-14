#include <iostream>
#include <vector>

using namespace std;

int main() {
  int n, m;
  cin >> n >> m;
  vector<int> a { 0 };
  for (int i = 0; i < n; i++) {
    int p;
    cin >> p;
    a.push_back(p);
  }
  vector<int> b { 0 };
  for (int i = 0; i < m; i++) {
    int p;
    cin >> p;
    b.push_back(p);
  }
  int ap = 0;
  int bp = 0;
  int count = 0;
  while (ap <= n && bp <= m) {
    if (ap % 2 == bp % 2 && a[ap] == b[bp]) {
      if (a[ap + 1] < b[bp + 1]) {
        ap += 2;
      } else {
        bp += 2;
      }
      count++;
    } else if (a[ap] < b[bp]) {
      ap++;
      if (ap <= n && (ap % 2 != bp % 2 || a[ap] < b[bp])) count++;
    } else if (b[bp] < a[ap]) {
      bp++;
      if (bp <= m && (ap % 2 != bp % 2 || b[bp] < a[ap])) count++;
    } else {
      ap++;
      bp++;
      if (ap <= n && bp <= m) {
        count++;
      }
    }
  }
  cout << count << endl;
  return 0;
}
