#include <iostream>
#include <algorithm>
#include <functional>
#include <vector>
#include <tuple>
#define iter(c) c.begin(), c.end()

using namespace std;

int main() {
  int n, m;
  cin >> n >> m;
  vector<int> a;
  for (int i = 0; i < n; i++) {
    int k;
    cin >> k;
    a.push_back(k);
  }
  sort(iter(a));
  vector<pair<int, int>> sep;
  for (int i = 0; i < n - 1; i++) {
    sep.emplace_back(a[i + 1] - a[i], i);
  }
  sort(iter(sep), greater<pair<int, int>>());
  sort(sep.begin(), sep.begin() + m - 1, [](pair<int, int> a, pair<int, int> b) { return a.second < b.second; });
  int cost = 0;
  int start = 0;
  for (int i = 0; i < m - 1; i++) {
    int end = sep[i].second;
    if (end != start) cost += a[end] - a[start];
    start = end + 1;
  }
  cost += a.back() - a[start];
  cout << cost << endl;
  return 0;
}
