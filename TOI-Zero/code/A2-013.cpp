#include <iostream>

using namespace std;

int main() {
  char b, t;
  int bm, s, tv;
  cin >> b >> bm;
  cin >> t >> s >> tv;
  int cal = 0;
  switch (b) {
    case 'H':
      cal += bm * 5;
      break;
    case 'O':
      cal += bm * 3;
      break;
    case 'J':
      cal += bm * 2;
      break;
  }
  switch (t) {
    case 'R':
      switch (s) {
        case 1:
          cal += tv * 12;
          break;
        case 2:
          cal += tv * 18;
          break;
        case 3:
          cal += tv * 25;
          break;
      }
      break;
    case 'T':
      switch (s) {
        case 1:
          cal += tv * 15;
          break;
        case 2:
          cal += tv * 20;
          break;
        case 3:
          cal += tv * 30;
          break;
      }
      break;
    case 'M':
      switch (s) {
        case 1:
          cal += tv * 10;
          break;
        case 2:
          cal += tv * 15;
          break;
        case 3:
          cal += tv * 20;
          break;
      }
      break;
  }
  cout << cal << endl;
  return 0;
}
