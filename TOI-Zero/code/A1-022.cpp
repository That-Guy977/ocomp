#include <iostream>
#include <string>

using namespace std;

const string zodiac[] {
  "capricorn",
  "aquarius",
  "pisces",
  "aries",
  "taurus",
  "gemini",
  "cancer",
  "leo",
  "virgo",
  "libra",
  "scorpio",
  "sagittarius",
};

const int threshold[] {
  20, 19, 21,
  20, 21, 22,
  23, 23, 23,
  24, 22, 22,
};

int main() {
  int d, m;
  cin >> d >> m;
  m--;
  if (d >= threshold[m]) m++;
  m %= 12;
  cout << zodiac[m] << endl;
  return 0;
}
