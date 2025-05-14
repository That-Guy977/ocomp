#include <iostream>
#include <string>

using namespace std;

const string vowels = "AEIOU";

int main() {
  int n;
  cin >> n;
  int c = 0;
  for (int i = 0; i < n; i++) {
    char ch;
    cin >> ch;
    if (vowels.find(ch) != string::npos) {
      c++;
    }
  }
  cout << c << endl;
  return 0;
}
