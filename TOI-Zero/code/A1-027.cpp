#include <iostream>
#include <algorithm>
#include <string>
#include <cctype>
#define iter(c) c.begin(), c.end()

using namespace std;

int main() {
  string s;
  cin >> s;
  transform(iter(s), s.begin(), [](char c) { return tolower(c); });
  reverse(iter(s));
  cout << s << endl;
  return 0;
}
