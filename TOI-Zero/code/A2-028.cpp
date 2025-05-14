#include <iostream>
#include <string>

using namespace std;

int main() {
  int n;
  cin >> n;
  string a, b;
  cin >> a >> b;
  int e = 0;
  for (int i = 0; i < n; i++) {
    if (a[i] + b[i] - '0' * 2 != 9) {
      e++;
    }
  }
  if (e == 0) {
    cout << "YES";
  } else {
    cout << "NO " << e;
  }
  cout << endl;
  return 0;
}
