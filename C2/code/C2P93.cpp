#include <iostream>

using namespace std;

int main() {
  int n;
  cin >> n;
  for (int i = 1; i <= n; i++) {
    if (i > 1) cout << " ";
    int found = 0;
    for (int j = 31; j >= 0; j--) {
      if (i & 1 << j) found = 1;
      if (found) {
        cout << !!(i & 1 << j);
      }
    }
  }
  cout << endl;
  return 0;
}
