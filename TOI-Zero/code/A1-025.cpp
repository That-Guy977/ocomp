#include <iostream>
#include <cctype>

using namespace std;

int main() {
  char r, s;
  cin >> r >> s;
  if (s == '0') {
    cin >> s;
  }
  r = toupper(r);
  s = toupper(s);
  switch (r) {
    case 'A':
      cout << "ace";
      break;
    case 'J':
      cout << "jack";
      break;
    case 'Q':
      cout << "queen";
      break;
    case 'K':
      cout << "king";
      break;
    case '1':
      cout << "10";
      break;
    default:
      cout << r;
      break;
  }
  cout << " of ";
  switch (s) {
    case 'D':
      cout << "diamonds";
      break;
    case 'H':
      cout << "hearts";
      break;
    case 'S':
      cout << "spades";
      break;
    case 'C':
      cout << "clubs";
      break;
  }
  cout << endl;
  return 0;
}
