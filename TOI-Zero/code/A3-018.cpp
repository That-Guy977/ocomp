#include <iostream>

using namespace std;

int main() {
  int l, n;
  cin >> l >> n;
  int sum = 0;
  for (int i = 1;; i++) {
    sum += i * i;
    if (sum > n) {
      cout << l - i + 1 << endl;
      break;
    }
  }
  return 0;
}
