#include <iostream>
#include <cmath>

using namespace std;

struct pos {
  int x, y;
};

int dist(pos&, pos&);
ostream& operator<<(ostream& c, pos& p) {
  c << p.x << " " << p.y << endl;
  return c;
}

int main() {
  int xs, ys;
  cin >> xs >> ys;
  pos startpos;
  cin >> startpos.x >> startpos.y;
  pos posxmx = startpos;
  pos posxmn = startpos;
  pos posymx = startpos;
  pos posymn = startpos;
  int n;
  cin >> n;
  for (int i = 0; i < n; i++) {
    pos wow;
    cin >> wow.x >> wow.y;
    if (wow.x > posxmx.x) posxmx = wow;
    if (wow.x < posxmn.x) posxmn = wow;
    if (wow.y > posymx.y) posymx = wow;
    if (wow.y < posymn.y) posymn = wow;
  }
  int total =
    dist(posxmx, posymx)
  + dist(posymx, posxmn)
  + dist(posxmn, posymn)
  + dist(posymn, posxmx);
  cout << posxmx << posymx << posxmn << posymn;
  cout << total << endl;
  return 0;
}

int dist(pos& a, pos& b) {
  return abs(a.x - b.x) + abs(a.y - b.y);
}
