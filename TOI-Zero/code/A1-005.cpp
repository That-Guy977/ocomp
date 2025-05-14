#include <iostream>
#include <string>

using namespace std;

const string seasons[] {
  "winter",
  "spring",
  "summer",
  "fall",
};

int main() {
  int m, d;
  cin >> m >> d;
  m--;
  if (d >= 21) m++;
  m %= 12;
  cout << seasons[m / 3] << endl;
  return 0;
}
