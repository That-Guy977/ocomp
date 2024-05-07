#include <iostream>

using namespace std;

int main() {
  int n;
  cin >> n;
  int pprev;
  int prev;
  cin >> prev;
  for (int i = 1; i < n; i++) {
    int x;
    cin >> x;
    if ((i == 1 || prev > pprev) && prev > x) {
      cout << i - 1 << endl;
      return 0;
    }
    pprev = prev;
    prev = x;
  }
  cout << n - 1 << endl;
  return 0;
}
