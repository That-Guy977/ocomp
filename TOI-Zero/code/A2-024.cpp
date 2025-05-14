#include <iostream>
#include <algorithm>

using namespace std;

int main() {
  int l, p;
  cin >> l >> p;
  int r, m, f;
  cin >> r >> m >> f;
  int rs = 0;
  int ms = 0;
  int fs = 0;
  for (int i = 0; i < p; i++) {
    int pos, s;
    cin >> pos >> s;
    if (pos % r == 0) rs += s;
    if (pos % m == 0) ms += s;
    if (pos % f == 0) fs += s;
  }
  int w = max({ rs, ms, fs });
  if (rs == w) cout << "Rabbit " << w << endl;
  if (ms == w) cout << "Monkey " << w << endl;
  if (fs == w) cout << "Frog " << w << endl;
  return 0;
}
