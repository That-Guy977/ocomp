#include <iostream>

using namespace std;

int main() {
  char s, b, t;
  int n;
  cin >> s >> b;
  cin >> t >> n;
  int p = 0;
  switch (s) {
    case 'S':
      p += 60;
      break;
    case 'M':
      p += 80;
      break;
    case 'L':
      p += 100;
      break;
  }
  if (b == 'T') p += 20;
  switch (t) {
    case 'P':
      p += n * 15;
      break;
    case 'E':
      p += n * 10;
      break;
  }
  cout << p << endl;
  return 0;
}
