#include <iostream>
#include <algorithm>
#include <string>
#include <cctype>
#define iter(c) c.begin(), c.end()

using namespace std;

const string mask = "love";

int main() {
  string a, b;
  cin >> a >> b;
  string res;
  int w = 0;
  int wgroup = 0;
  int curr = 0;
  for (int i = 0; i < max(a.length(), b.length()); i++) {
    if (
      mask.find(tolower(a[i % a.length()])) != string::npos
      || mask.find(tolower(b[i % b.length()])) != string::npos
    ) {
      res += 'w';
      w++;
      curr++;
    } else {
      res += '$';
      if (curr > wgroup) wgroup = curr;
      curr = 0;
    }
  }
  if (curr > wgroup) wgroup = curr;
  if (w % 2 != 0) {
    res += to_string(wgroup);
  } else if (wgroup < 2) {
    res += '#';
  }
  cout << res << endl;
  return 0;
}
