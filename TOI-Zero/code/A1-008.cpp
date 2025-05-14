#include <iostream>
#include <string>

using namespace std;

int main() {
  string id;
  cin >> id;
  cout << (id.length() == 13 ? "yes" : "no") << endl;
  return 0;
}
