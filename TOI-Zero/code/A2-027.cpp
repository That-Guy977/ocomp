#include <iostream>

using namespace std;

int main() {
  int n;
  cin >> n;
  int mx = 0;
  int mxc = 0;
  for (int i = 0; i < n; i++) {
    int s;
    cin >> s;
    if (s > mx) {
      mx = s;
      mxc = 1;
    } else if (s == mx) {
      mxc++;
    }
  }
  cout << mx << endl;
  cout << mxc << endl;
  return 0;
}
