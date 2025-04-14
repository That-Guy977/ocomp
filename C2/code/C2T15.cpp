#include <iostream>

using namespace std;

int main() {
  int t;
  cin >> t;
  for (int ti = 0; ti < t; ti++) {
    long n;
    cin >> n;
    cout << (n % 2 ? n : 1) << endl;
  }
  return 0;
}
