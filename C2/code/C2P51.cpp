#include <iostream>

using namespace std;

int main() {
  int n;
  cin >> n;
  long mx = 0;
  long sum = 0;
  for (int i = 0; i < n; i++) {
    int a;
    cin >> a;
    if (sum + a > 0) {
      sum += a;
    } else {
      sum = 0;
    }
    if (sum > mx) mx = sum;
  }
  cout << mx << endl;
  return 0;
}
