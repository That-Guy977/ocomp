#include <iostream>

using namespace std;

int main() {
  char gw, g;
  int nw, n;
  cin >> gw >> nw;
  cin >> g >> n;
  if (g == gw && n == nw) {
    cout << 1000000;
  } else if (n == nw) {
    cout << 100000;
  } else if (g == gw && n % 1000 == nw % 1000) {
    cout << 2000;
  } else if (g == gw && n % 100 == nw % 100) {
    cout << 1000;
  } else if (n % 1000 == nw % 1000) {
    cout << 200;
  } else if (n % 100 == nw % 100) {
    cout << 100;
  } else if (g == gw) {
    cout << 20;
  } else {
    cout << 0;
  }
  cout << endl;
  return 0;
}
