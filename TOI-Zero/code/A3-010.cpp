#include <iostream>

using namespace std;

int main() {
  int n, k, t;
  cin >> n >> k >> t;
  t--;
  int p = 0;
  int count = 1;
  do {
    p += k;
    p %= n;
    count++;
  } while (p != 0 && p != t);
  if (p == 0) count--;
  cout << count << endl;
  return 0;
}
