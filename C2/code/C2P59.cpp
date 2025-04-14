#include <iostream>
#include <algorithm>

using namespace std;

int main() {
  int c;
  cin >> c;
  for (int ci = 0; ci < c; ci++) {
    int n, t;
    cin >> n >> t;
    int a[n];
    for (int i = 0; i < n; i++) {
      cin >> a[i];
    }
    int *base = new int[t + 1]{};
    int *next = new int[t + 1]{};
    for (int i = 0; i < n; i++) {
      for (int c = 0; c <= t; c++) {
        next[c] = max(base[c], a[i] <= c ? base[c - a[i]] + a[i] : 0);
      }
      swap(base, next);
    }
    cout << (base[t] == t ? "YES" : "NO") << endl;
    delete[] base;
    delete[] next;
  }
  return 0;
}
