#include <iostream>
#include <set>
#include <tuple>

using namespace std;

int main() {
  int n;
  cin >> n;
  set<pair<int, int>> models;
  for (int i = 0; i < n; i++) {
    int p, v;
    cin >> p >> v;
    models.emplace(p, v);
  }
  int count = 0;
  int mxv = 0;
  for (auto [p, v] : models) {
    if (v > mxv) mxv = v;
    else count++;
  }
  cout << count << endl;
  return 0;
}
