#include <iostream>
#include <string>

using namespace std;

int main() {
  string first, last;
  int age;
  cin >> first >> last >> age;
  if (first.length() > 5 && last.length() > 5) {
    cout << first.substr(0, 2) << last.back() << age % 10;
  } else {
    cout << first.front() << age << last.back();
  }
  cout << endl;
  return 0;
}
