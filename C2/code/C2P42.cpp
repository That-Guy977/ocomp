#include <iostream>

using namespace std;

int main() {
  int a, b, c;
  cin >> a >> b >> c;
  for (int x = -100; x <= 100; x++) {
    for (int y = -100; y <= 100; y++) {
      int z = a - x - y;
      if (
        x != y && x != z && y != z
        && x * y * z == b && x*x + y*y + z*z == c
      ) {
        cout << x << " " << y << " " << z << endl;
        return 0;
      }
    }
  }
  cout << "No solution." << endl;
  return 0;
}
