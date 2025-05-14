#include <iostream>
#include <algorithm>
#include <functional>
#include <vector>
#define iter(c) c.begin(), c.end()

using namespace std;

int main() {
  int n;
  cin >> n;
  vector<int> x;
  for (int i = 0; i < n; i++) {
    int d;
    cin >> d;
    x.push_back(d);
  }
  sort(iter(x), greater());
  int e = 0;
  for (int i = 0; i < n; i++) {
    e += x[i] * (i / 11 * 2 + (i % 11 == 0 ? 1 : 2));
  }
  cout << e << endl;
  return 0;
}
