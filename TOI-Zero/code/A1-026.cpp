#include <iostream>

using namespace std;

int main() {
  int e = 0;
  int o = 0;
  for (int i = 0; i < 3; i++) {
    int n;
    cin >> n;
    if (n % 2 == 0) {
      e++;
    } else {
      o++;
    }
  }
  cout << "even " << e << endl;
  cout << "odd " << o << endl;
  return 0;
}
