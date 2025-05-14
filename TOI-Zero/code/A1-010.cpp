#include <iostream>
#include <cctype>

using namespace std;

int main() {
  int a;
  char t;
  cin >> a >> t;
  cout << (a <= 18 || toupper(t) == 'S' ? 20 : 50) << endl;
  return 0;
}
