#include <iostream>
#include <algorithm>

using namespace std;

int main() {
  int n, mw;
  cin >> n >> mw;
  int w[n], a[n];
  for (int i = 0; i < n; i++) {
    cin >> w[i];
  }
  for (int i = 0; i < n; i++) {
    cin >> a[i];
  }
  int *base = new int[mw + 1]{};
  int *next = new int[mw + 1]{};
  for (int i = 0; i < n; i++) {
    for (int c = 0; c <= mw; c++) {
      next[c] = max(base[c], w[i] <= c ? base[c - w[i]] + a[i]: 0);
    }
    swap(base, next);
  }
  cout << base[mw] << endl;
  return 0;
}
