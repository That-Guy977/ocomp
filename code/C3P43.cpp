#include <iostream>
#include <string>

using namespace std;

int main() {
  int q;
  cin >> q;
  for (int qi = 0; qi < q; qi++) {
    string a;
    long n;
    int k;
    cin >> a >> n >> k;
    int len = a.length();
    long x = 0;
    for (int i = 0; i < len; i++) {
      x *= 10;
      x += a[i] - '0';
      x %= k;
    }
    long v = 1;
    while (n) {
      if (n & 1) {
        v *= x;
        v %= k;
      }
      x *= x;
      x %= k;
      n >>= 1;
    }
    cout << v << endl;
  }
  return 0;
}
