#include <iostream>

using namespace std;

int main() {
  int l, n;
  cin >> l >> n;
  for (int i = 0;; i++) {
    int s = 0;
    for (int j = 1; j <= l; j++) {
      s += i * l + j;
    }
    if (n <= s) {
      cout << i + 1 << endl;
      break;
    }
    n -= s;
  }
  return 0;
}
