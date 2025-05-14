#include <iostream>
#include <cctype>

using namespace std;

int main() {
  int t;
  char unit;
  cin >> t >> unit;
  unit = toupper(unit);
  if (t <= (unit == 'C' ? 0 : 32)) {
    cout << "solid";
  } else if (t >= (unit == 'C' ? 100 : 212)) {
    cout << "gas";
  } else {
    cout << "liquid";
  }
  cout << endl;
  return 0;
}
