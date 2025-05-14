#include <iostream>

using namespace std;

int main() {
  int n;
  cin >> n;
  n -= n % 10;
  bool first = true;
  for (; n >= 0; n -= 10) {
    if (!first) cout << " ";
    first = false;
    cout << n;
  }
  cout << endl;
  return 0;
}
