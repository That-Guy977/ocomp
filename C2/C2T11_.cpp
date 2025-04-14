#include <iostream>

using namespace std;

int main() {
  int n, m;
  cin >> n >> m;
  int a[n];
  for (int i = 0; i < n; i++) {
    cin >> a[i];
  }
  for (int i = 1; i <= m; i++) {
    int b = 0;
    for (int j = 0; j < n; j++) {
      b += a[j] / i;
    }
    cout << b << endl;
  }
  return 0;
}
