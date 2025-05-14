#include <iostream>
#include <string>

using namespace std;

int main() {
  int n;
  cin >> n;
  for (int i = 0; i < 3; i++) {
    if (n > 0) {
      cout << string(n, '*');
    }
    cout << endl;
    n -= 2;
  }
  return 0;
}
