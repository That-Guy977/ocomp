#include <iostream>
#include <algorithm>
#include <string>
#define iter(c) c.begin(), c.end()

using namespace std;

const string vowels = "aeiou";

int main() {
  string s;
  cin >> s;
  int v = count_if(iter(s), [](char ch) { return vowels.find(ch) != string::npos; });
  cout << v << endl;
  return 0;
}
