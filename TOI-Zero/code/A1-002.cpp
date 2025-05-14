#include <iostream>

using namespace std;

int main() {
  int m;
  cin >> m;
  cout << "10 = " << m / 10 << endl;
  m %= 10;
  cout << "5 = " << m / 5 << endl;
  m %= 5;
  cout << "2 = " << m / 2 << endl;
  m %= 2;
  cout << "1 = " << m << endl;
  return 0;
}
