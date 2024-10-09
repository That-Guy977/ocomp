#include <iostream>
#include <queue>
#include <array>
#include <tuple>

using namespace std;

array<pair<int, int>, 4> moves {{
  {  1,  0 },
  { -1,  0 },
  {  0,  1 },
  {  0, -1 },
}};

int main() {
  int n;
  cin >> n;
  char plot[n * n];
  for (int i = 0; i < n; i++) {
    for (int j = 0; j < n; j++) {
      cin >> plot[i * n + j];
    }
  }
  unsigned maxa = 0;
  unsigned minp = -1;
  for (int i = 0; i < n; i++) {
    for (int j = 0; j < n; j++) {
      if (plot[i * n + j] == '#') {
        int a = 0, p = 0;
        queue<pair<int, int>> search;
        search.push({ i, j });
        while (!search.empty()) {
          auto [x, y] = search.front();
          search.pop();
          if (x < 0 || x >= n || y < 0 || y >= n || plot[x * n + y] == '.') p++;
          else if (plot[x * n + y] == '#') {
            a++;
            plot[x * n + y] = '-';
            for (auto [dx, dy] : moves) {
              search.push({ x + dx, y + dy });
            }
          }
        }
        if (a > maxa) {
          maxa = a;
          minp = p;
        } else if (a == maxa && p < minp) {
          minp = p;
        }
      }
    }
  }
  cout << maxa << " " << minp << endl;
  return 0;
}
