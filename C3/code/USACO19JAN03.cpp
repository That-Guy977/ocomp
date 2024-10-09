#include <iostream>
#include <algorithm>
#include <functional>
#include <set>
#include <tuple>

using namespace std;

int main() {
  int n;
  cin >> n;
  set<pair<int, int>, greater<pair<int, int>>> mountains;
  for (int i = 0; i < n; i++) {
    int x, y;
    cin >> x >> y;
    mountains.emplace(y, x);
  }
  set<pair<int, int>, greater<pair<int, int>>> peaks;
  for (const pair<int, int>& mountain : mountains) {
    if (none_of(peaks.begin(), peaks.end(), [&mountain](const pair<int, int>& peak) {
      auto [h, p] = peak;
      auto [y, x] = mountain;
      return x < p ? y - x <= h - p : y + x <= h + p;
    })) {
      peaks.insert(mountain);
    }
  }
  cout << peaks.size() << endl;
  return 0;
}
