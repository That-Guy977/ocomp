#include <iostream>

using namespace std;

int main() {
  int n;
  cin >> n;
  long a[n];
  cin >> a[0];
  for (int i = 1; i < n; i++) {
    cin >> a[i];
    a[i] += a[i - 1];
  }
  long mx = 0;
  for (int i = 0; i < n; i++) {
    for (int j = i; j < n; j++) {
      long res = a[j] - (i ? a[i - 1] : 0);
      if (res > mx) mx = res;
    }
  }
  cout << mx << endl;
  return 0;
}
