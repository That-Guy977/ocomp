#include <iostream>

using namespace std;

int main() {
  int a;
  char op;
  cin >> a >> op;
  int b = a / 10 + a % 10 * 10;
  int res = op == '+' ? a + b : a * b;
  cout << a << " " << op << " " << b << " = " << res << endl;
  return 0;
}
