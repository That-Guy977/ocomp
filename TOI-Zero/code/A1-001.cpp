#include <iostream>
#include <string>

using namespace std;

int main() {
  string a, b;
  cin >> a >> b;
  cout << "Hello " << a << " " << b << endl;
  cout << a.substr(0, 2) << b.substr(0, 2) << endl;
  return 0;
}
