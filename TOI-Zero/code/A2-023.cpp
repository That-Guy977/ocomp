#include <iostream>
#include <string>
#include <cctype>

using namespace std;

int main() {
  string s;
  cin >> s;
  bool p = false;
  char prev = 0;
  int error = -1;
  int a = 0;
  int curra = 0;
  for (int i = 0; i < s.length(); i++) {
    char ch = toupper(s[i]);
    if (
      prev == 'R' && ch != 'A'
      || ch == 'A' && prev != 'R' && prev != 'A'
      || prev == 'B' && ch != 'I' && ch != 'T'
    ) {
      error = i;
      break;
    }
    if (ch == 'R' || ch == 'B' || ch == 'A') p = true;
    if (ch == 'A') {
      curra++;
      if (curra > a) a = curra;
    } else {
      curra = 0;
    }
    prev = ch;
  }
  if (error == -1 && (prev == 'R' || prev == 'B')) error = s.length() - 1;
  if (error != -1) {
    cout << "no " << error;
  } else if (p) {
    cout << "yes " << a;
  } else {
    cout << "unknown " << s.length();
  }
  cout << endl;
  return 0;
}
