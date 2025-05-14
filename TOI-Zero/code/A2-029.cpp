#include <iostream>

using namespace std;

int main() {
  int n;
  cin >> n;
  cout << 0 << endl;
  for (int i = 2; i <= n; i++) {
    cout << 0 << " ";
    for (int j = 0; j < i - 2; j++) {
      cout << (i == n ? 0 : 1) << " ";
    }
    cout << 0 << endl;
  }
  return 0;
}
