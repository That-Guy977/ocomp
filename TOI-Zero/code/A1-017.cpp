#include <iostream>

using namespace std;

int main() {
  int y1, m1, d1;
  cin >> y1 >> m1 >> d1;
  int y2, m2, d2;
  cin >> y2 >> m2 >> d2;
  int date1 = y1 * 10000 + m1 * 100 + d1;
  int date2 = y2 * 10000 + m2 * 100 + d2;
  if (date1 < date2) {
    cout << 1;
  } else if (date1 > date2) {
    cout << 2;
  } else {
    cout << 0;
  }
  cout << endl;
  return 0;
}
