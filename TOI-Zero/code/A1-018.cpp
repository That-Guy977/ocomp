#include <iostream>

using namespace std;

int main() {
  int n;
  cin >> n;
  if (n < 0) {
    cout << "Error : Please input positive number";
  } else if (n == 0 || n > 9) {
    cout << "Error : Out of range";
  } else {
    if (n == 4) {
      cout << "IV";
    } else if (n == 9) {
      cout << "IX";
    } else {
      if (n >= 5) {
        n -= 5;
        cout << "V";
      }
      cout << string(n, 'I');
    }
  }
  cout << endl;
  return 0;
}
