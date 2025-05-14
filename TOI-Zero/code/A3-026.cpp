#include <iostream>
#include <algorithm>
#include <string>
#define iter(c) c.begin(), c.end()

using namespace std;

int main() {
  int n, m;
  cin >> n >> m;
  string a[n];
  for (int i = 0; i < n; i++) {
    cin >> a[i];
  }
  for (int i = 0; i < n; i++) {
    string b;
    cin >> b;
    transform(
      iter(a[i]),
      b.begin(),
      b.begin(),
      [](char ca, char cb) {
        if (ca == '+') {
          return cb == 'x' ? '*' : '+';
        } else {
          return cb == 'x' ? 'x' : '-';
        }
      }
    );
    cout << b << endl;
  }
  return 0;
}
