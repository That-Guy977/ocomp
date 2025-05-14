#include <iostream>
#include <algorithm>
#include <iterator>
#include <vector>
#define iter(c) c.begin(), c.end()
#define riter(c) c.rbegin(), c.rend()

using namespace std;

int main() {
  int n, k;
  cin >> n >> k;
  vector<int> ts;
  for (int i = 0; i < n; i++) {
    int t;
    cin >> t;
    ts.push_back(t);
  }
  sort(iter(ts));
  double ft = *ts.begin();
  double cut = ft * k;
  vector<double> pt;
  transform(iter(ts), back_inserter(pt), [&](double t) { return 1/(1/ft - 1/t); });
  cout << distance(upper_bound(riter(pt), cut), pt.rend()) << endl;
  return 0;
}
