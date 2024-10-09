#include <iostream>

using namespace std;

int main() {
  int n;
  cin >> n;
  int as[n], ss[n], sz = 0;
  for (int i = 0; i < n; i++) {
    int a;
    cin >> a;
    int s = 1;
    while (sz && a >= as[sz - 1]) {
      s += ss[--sz];
    }
    as[sz] = a;
    ss[sz] = s;
    sz++;
    cout << s << " ";
  }
  cout << endl;
  return 0;
}
