#include <iostream>
#include <algorithm>
#include <string>
#define iter(c) c.begin(), c.end()

using namespace std;

int main() {
  string n;
  cin >> n;
  reverse(iter(n));
  cout << n << endl;
  return 0;
}
