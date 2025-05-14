#include <iostream>
#include <cmath>

using namespace std;

int main() {
  int n;
  cin >> n;
  int l = ceil(sqrt(n));
  int steps = (l - 1) * 2;
  if (n % 2 != l % 2) steps--;
  cout << steps << endl;
  return 0;
}
