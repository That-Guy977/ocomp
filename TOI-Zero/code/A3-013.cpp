#include <iostream>

using namespace std;

int main() {
  int n, s;
  cin >> n >> s;
  int mn = s;
  int mx = s;
  for (int i = 0; i < n; i++) {
    int h;
    cin >> h;
    if (h % 12 == 0) {
      mn -= h / 3 * 10;
      mx -= h / 4 * 10;
    } else if (h % 3 == 0) {
      mn -= h / 3 * 10;
      mx -= h / 3 * 10;
    } else if (h % 4 == 0) {
      mn -= h / 4 * 10;
      mx -= h / 4 * 10;
    }
  }
  cout << mn << " " << mx << endl;
  return 0;
}
