#include <iostream>

using namespace std;

int main() {
  int a, b, c;
  cin >> a >> b >> c;
  if (a < b && b < c) {
    cout << "increasing";
  } else if (a > b && b > c) {
    cout << "decreasing";
  } else {
    cout << "neither";
  }
  cout << endl;
  return 0;
}
