#include <iostream>
#include <map>

using namespace std;

int main() {
  int n, k;
  cin >> n >> k;
  int s[n];
  int o = -1;
  for (int i = 0; i < n; i++) {
    cin >> s[i];
    if (s[i] == k) o = i;
  }
  int c[n];
  c[o] = 0;
  for (int i = o + 1; i < n; i++) {
    c[i] = (i ? c[i - 1] : 0) + (s[i] == k ? 0 : s[i] > k ? 1 : -1);
  }
  for (int i = o - 1; i >= 0; i--) {
    c[i] = (i < o - 1 ? c[i + 1] : 0) + (s[i] == k ? 0 : s[i] > k ? 1 : -1);
  }
  map<int, int> l{ { 0, 1 } }, r{ { 0, 1 } };
  for (int i = 0; i < o; i++) {
    l[c[i]]++;
  }
  for (int i = o + 1; i < n; i++) {
    r[c[i]]++;
  }
  int p = 0;
  for (auto [x, lp] : l) {
    p += r[-x] * lp;
  }
  cout << p << endl;
  return 0;
}
