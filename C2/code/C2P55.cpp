#include <iostream>
#include <map>

using namespace std;

int main() {
  int n;
  cin >> n;
  long a[n];
  for (int i = 0; i < n; i++) {
    cin >> a[i];
  }
  long p[2 * n - 1];
  for (int i = 0; i < 2 * n - 1; i++) {
    p[i] = 0;
  }
  for (int i = 0; i < n; i++) {
    int b;
    cin >> b;
    for (int j = 0; j < n; j++) {
      p[i + j] += a[j] * b;
    }
  }
  for (int i = 0; i < 2 * n - 1; i++) {
    cout << p[i] << endl;
  }
  return 0;
}
