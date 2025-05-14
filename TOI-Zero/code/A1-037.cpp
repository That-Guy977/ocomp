#include <iostream>

using namespace std;

int main() {
  int n;
  cin >> n;
  while (n >= 1000) {
    cout << "M";
    n -= 1000;
  }
  if (n >= 900) {
    cout << "CM";
    n -= 900;
  }
  if (n >= 500) {
    cout << "D";
    n -= 500;
  }
  if (n >= 400) {
    cout << "CD";
    n -= 400;
  }
  while (n >= 100) {
    cout << "C";
    n -= 100;
  }
  if (n >= 90) {
    cout << "XC";
    n -= 90;
  }
  if (n >= 50) {
    cout << "L";
    n -= 50;
  }
  if (n >= 40) {
    cout << "XL";
    n -= 40;
  }
  while (n >= 10) {
    cout << "X";
    n -= 10;
  }
  if (n >= 9) {
    cout << "IX";
    n -= 9;
  }
  if (n >= 5) {
    cout << "V";
    n -= 5;
  }
  if (n >= 4) {
    cout << "IV";
    n -= 4;
  }
  while (n >= 1) {
    cout << "I";
    n -= 1;
  }
  cout << endl;
  return 0;
}
