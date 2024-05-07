#include <iostream>

using namespace std;

int main() {
  unsigned long n;
  cin >> n;
  unsigned long x[n];
  unsigned long y[n];
  unsigned long sumx = 0;
  unsigned long sumy = 0;
  for (int i = 0; i < n; i++) {
    cin >> x[i];
    sumx += x[i];
  }
  for (int i = 0; i < n; i++) {
    cin >> y[i];
    sumy += y[i];
  }
  unsigned long sumxy = 0;
  for (int i = 0; i < n; i++) {
    sumxy += x[i] * y[i];
    sumxy %= 2560;
  }
  sumx %= 2560;
  sumy %= 2560;
  cout << n * (n - 1) / 2 % 2560 << endl;
  cout << (n * sumxy - sumx * sumy % 2560 + 2560) % 2560 << endl;
  return 0;
}
