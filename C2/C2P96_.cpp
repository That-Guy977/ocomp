#include <iostream>
#include <map>

using namespace std;

int main() {
  int n;
  cin >> n;
  map<int, long> s;
  for (int i = 0; i < n; i++) {
    int x;
    cin >> x;
    s[x]++;
  }
  int g;
  cin >> g;
  long c = g % 2 == 0 ? s[g / 2] * (s[g / 2] - 1) / 2 : 0;
  for (auto [x, k] : s) {
    if (x >= g / 2) break;
    c += k * s[g - x];
  }
  cout << c << endl;
  return 0;
}
