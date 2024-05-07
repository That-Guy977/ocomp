#include <iostream>
#include <algorithm>
#include <functional>
#include <map>

using namespace std;

int main() {
  map<int, int, greater<int>> polynomial;
  int n;
  cin >> n;
  for (int i = 0; i < n; i++) {
    int p, c;
    cin >> p >> c;
    polynomial[p] += c;
  }
  int m;
  cin >> m;
  for (int i = 0; i < m; i++) {
    int p, c;
    cin >> p >> c;
    polynomial[p] += c;
  }
  for (const pair<int, int> &term : polynomial) {
    if (term.second) {
      cout << term.first << " " << term.second << endl;
    }
  }
  if (none_of(polynomial.begin(), polynomial.end(), [](const pair<int, int> &entry) { return entry.second; })) {
    cout << 0 << endl;
  }
  return 0;
}
