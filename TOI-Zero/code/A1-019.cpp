#include <iostream>

using namespace std;

int main() {
  int a, b, c;
  cin >> a >> b >> c;
  if (a == b && a == c) {
    cout << "all the same";
  } else if (a != b && a != c && b != c) {
    cout << "all different";
  } else {
    cout << "neither";
  }
  cout << endl;
  return 0;
}
