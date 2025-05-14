#include <iostream>

using namespace std;

int main() {
  int m, f;
  cin >> m >> f;
  int s = m + f;
  cout << s << endl;
  cout << (s >= 50 ? "pass" : "fail") << endl;
  return 0;
}
