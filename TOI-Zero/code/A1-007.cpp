#include <iostream>
#include <string>

using namespace std;

const string vowels = "aeiou";

int main() {
  char c;
  cin >> c;
  cout << (vowels.find(c) != string::npos ? "yes" : "no") << endl;
  return 0;
}
