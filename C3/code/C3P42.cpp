#include <iostream>
#include <algorithm>
#include <map>
#include <string>

using namespace std;

int main() {
  string str;
  cin >> str;
  int len = str.length();
  long anagrams = 0;
  for (int l = 1; l < len; l++) {
    map<string, int> groups;
    for (int i = 0; i <= len - l; i++) {
      string sub = str.substr(i, l);
      sort(sub.begin(), sub.end());
      anagrams += groups[sub]++;
    }
  }
  cout << anagrams << endl;
  return 0;
}
