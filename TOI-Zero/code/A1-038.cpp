#include <iostream>

using namespace std;

int main() {
  int n;
  cin >> n;
  for (int i = 1; i <= n; i++) {
    cout << (i % 5 == 0 ? 'X' : '*');
  }
  cout << endl;
  return 0;
}
