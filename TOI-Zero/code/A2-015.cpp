#include <iostream>

using namespace std;

int main() {
  int w, l, layers, p;
  cin >> w >> l >> layers >> p;
  int t = (w + l) * 2 * layers;
  cout << t << endl;
  cout << t * p << endl;
  return 0;
}
