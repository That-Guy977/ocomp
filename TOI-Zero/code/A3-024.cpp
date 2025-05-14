#include <iostream>
#include <set>
#include <tuple>

using namespace std;

int main() {
  int n, l;
  cin >> n >> l;
  set<pair<int, int>> routes;
  for (int i = 0; i < n; i++) {
    int s, t;
    cin >> s >> t;
    routes.emplace(t, s);
  }
  int count = 0;
  int end = -1;
  for (auto [t, s] : routes) {
    if (s > end) {
      end = t;
      count++;
    }
  }
  cout << count << endl;
  return 0;
}
