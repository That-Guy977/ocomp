#include <iostream>

using namespace std;

int main() {
  int n;
  cin >> n;
  int p = 1;
  for (; n > 0; n--) {
    p *= n;
  }
  cout << p << endl;
  return 0;
}
