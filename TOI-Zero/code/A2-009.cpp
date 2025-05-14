#include <iostream>
#include <iterator>
#include <vector>
#include <map>

using namespace std;

int main() {
  int n, c;
  cin >> n >> c;
  map<int, map<int, int>> res;
  for (int i = 1; i <= n; i++) {
    for (int j = 1; j <= n; j++) {
      int w;
      cin >> w;
      res[i][j] = w;
    }
  }
  vector<int> t;
  for (int i = 1; i <= n; i++) {
    t.push_back(i);
  }
  while (t.size() > 1) {
    for (auto it = t.begin(); it != t.end(); ++it) {
      auto a = *it;
      auto b = *next(it);
      int w = res[a][b];
      if (c == a && w != a) {
        w = a;
        c = 0;
      }
      if (c == b && w != b) {
        w = b;
        c = 0;
      }
      it = t.insert(t.erase(it, next(next(it))), w);
    }
  }
  cout << t[0] << endl;
  return 0;
}
