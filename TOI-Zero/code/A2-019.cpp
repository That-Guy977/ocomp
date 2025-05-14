#include <iostream>
#include <string>
#include <cctype>

using namespace std;

int main() {
  string s;
  cin >> s;
  int tlen = -1;
  int curr = -1;
  for (char ch : s) {
    if (curr == -1) {
      if (toupper(ch) == 'B') {
        curr++;
      }
    } else if (toupper(ch) == 'U') {
      curr++;
    } else {
      if (curr > tlen) tlen = curr;
      curr = -1;
    }
  }
  if (curr > tlen) tlen = curr;
  if (tlen >= 2) {
    cout << "Yes " << tlen;
  } else if (tlen >= 0) {
    bool b = false;
    for (char ch : s) {
      if (!b) cout << ch;
      else cout << 'U';
      if (toupper(ch) == 'B') b = true;
    }
  } else {
    for (int i = 0; i < s.length(); i++) {
      cout << "BUU"[i % 3];
    }
  }
  cout << endl;
  return 0;
}
