#include <iostream>

using namespace std;

int main() {
  int y, v;
  cin >> y >> v;
  if (y <= 1990) {
    if (v <= 1500) {
      cout << 1250;
    } else if (v <= 2000) {
      cout << 1400;
    } else {
      cout << 2000;
    }
  } else if (y < 2000) {
    if (v <= 1500) {
      cout << 1100;
    } else if (v <= 2000) {
      cout << 1300;
    } else {
      cout << 1700;
    }
  } else {
    if (v <= 1500) {
      cout << 1000;
    } else if (v <= 2000) {
      cout << 1200;
    } else {
      cout << 1500;
    }
  }
  cout << endl;
  return 0;
}
