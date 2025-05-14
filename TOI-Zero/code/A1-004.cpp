#include <iostream>

using namespace std;

int main() {
  int w, m, f;
  cin >> w >> m >> f;
  cout << (w >= 5 && m >= 20 && f >= 25 ? "pass" : "fail") << endl;
  return 0;
}
