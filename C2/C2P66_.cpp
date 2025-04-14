#include <iostream>

using namespace std;

int main() {
  int t;
  cin >> t;
  for (int ti = 0; ti < t; ti++) {
    int k;
    cin >> k;
    if (k == 1) cout << 0 << endl;
    else {
      k--;
      int d = 1;
      int w = 9;
      while (k > w * d) {
        k -= w * d;
        w *= 10;
        d++;
      }
      k--;
      int n = w / 9 + k / d;
      int p = d - (k % d) - 1;
      for (int i = 0; i < p; i++) {
        n /= 10;
      }
      n %= 10;
      cout << n << endl;
    }
  }
  return 0;
}
