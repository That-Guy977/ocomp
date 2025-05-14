#include <iostream>
#include <algorithm>
#include <vector>
#include <cmath>
#define iter(c) c.begin(), c.end()

using namespace std;

int main() {
  int n;
  cin >> n;
  vector<int> xs;
  vector<int> ys;
  for (int i = 0; i < n; i++) {
    int x, y;
    cin >> x >> y;
    int xp = x - y;
    int yp = x + y;
    xs.push_back(xp);
    ys.push_back(yp);
  }
  sort(iter(xs));
  sort(iter(ys));
  long dist = 0;
  for (int x : xs) {
    dist += abs(x - xs[n / 2]);
  }
  for (int y : ys) {
    dist += abs(y - ys[n / 2]);
  }
  cout << dist << endl;
  return 0;
}
