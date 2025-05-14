#include <iostream>

using namespace std;

int main() {
  int y;
  cin >> y;
  cout << (y % 4 == 0 && (y % 100 != 0 || y % 400 == 0 || y < 1582) ? "yes" : "no") << endl;
  return 0;
}
