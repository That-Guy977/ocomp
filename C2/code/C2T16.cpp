#include <iostream>

using namespace std;

int main() {
  int n;
  cin >> n;
  int a[n];
  int mx = 0;
  long sum = 0;
  for (int i = 0; i < n; i++) {
    cin >> a[i];
    sum += a[i];
    if (a[i] > mx) mx = a[i];
  }
  long b[n];
  for (int i = 0; i < n; i++) {
    b[i] = a[i];
    int x = i - 1;
    int y = i + 1;
    while (x >= 0 && b[i] > a[x] || y < n && b[i] > a[y]) {
      if (x >= 0 && b[i] > a[x]) b[i] += a[x--];
      if (y < n && b[i] > a[y]) b[i] += a[y++];
      if (b[i] > mx) {
        b[i] = sum;
        break;
      }
    }
  }
  for (int i = 0; i < n; i++) {
    if (i) cout << " ";
    cout << b[i];
  }
  cout << endl;
  return 0;
}
