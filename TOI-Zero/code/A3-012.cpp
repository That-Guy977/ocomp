#include <iostream>
#include <map>
#include <set>

using namespace std;

int main() {
  int n, s;
  cin >> n >> s;
  map<int, int> c;
  for (int i = 1; i <= n; i++) {
    int r;
    cin >> r;
    c[i] = r;
  }
  int m = s;
  int count = 0;
  set<int> rs;
  do {
    rs.insert(m);
    m = c[m];
  } while (!rs.count(m) && m != 0);
  cout << rs.size() << endl;
  return 0;
}
