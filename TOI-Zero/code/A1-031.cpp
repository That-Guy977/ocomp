#include <iostream>

using namespace std;

int main() {
  string n;
  cin >> n;
  for (int i = n.length() - 3; i > 0; i -= 3) {
    n.insert(i, ",");
  }
  cout << n << endl;
  return 0;
}
