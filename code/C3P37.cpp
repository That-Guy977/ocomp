#include <iostream>

using namespace std;

int main() {
  int n, s;
  cin >> n >> s;
  int x[n + 1] { 0 };
  for (int i = 1; i <= n; i++) {
    cin >> x[i];
    x[i] += x[i - 1];
  }
  unsigned int min = -1;
  if (x[n] >= s) {
    for (int l = 0, r = 0; r <= n; r++) {
      if (x[r] < s) continue;
      while (x[r] - x[l + 1] >= s) l++;
      if (r - l < min) min = r - l;
    }
  }
  cout << (int)min << endl;
  return 0;
}
