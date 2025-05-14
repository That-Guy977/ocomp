#include <iostream>

using namespace std;

int main() {
  int l, n;
  cin >> l >> n;
  int h[l + 1];
  for (int i = 0; i <= l; i++) {
    h[i] = 0;
  }
  for (int i = 0; i < n; i++) {
    int a, b;
    cin >> a >> b;
    h[a]++;
    h[b]--;
  }
  int mx = 0;
  int curr = 0;
  for (int i = 0; i <= l; i++) {
    curr += h[i];
    if (curr > mx) mx = curr;
  }
  cout << mx << endl;
  return 0;
}
