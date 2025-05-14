#include <iostream>
#include <string>

using namespace std;

int main() {
  string id;
  cin >> id;
  cout << (id.substr(2, 2) == "16" ? "yes" : "no") << endl;
  return 0;
}
