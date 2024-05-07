#include <iostream>
#include <algorithm>

using namespace std;

int main() {
  int n;
  cin >> n;
  int mx = 0;
  int sum = 0;
  for (int i = 0; i < n; i++) {
    int t;
    cin >> t;
    if (t > mx) mx = t;
    sum += t;
  }
  cout << max(2 * mx, sum) << endl;
  return 0;
}
