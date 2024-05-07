#include <iostream>
#include <vector>
#include <map>
#include <set>
#include <tuple>

using namespace std;

int main() {
  int n, m;
  cin >> n >> m;
  int c[n];
  cin >> c[0];
  for (int i = 1; i < n; i++) {
    cin >> c[i];
    c[i] += c[i - 1];
  }
  for (int i = 0; i < m; i++) {
    int x, y;
    cin >> x >> y;
    cout << c[y] - (x ? c[x - 1] : 0) << endl;
  }
  return 0;
}
