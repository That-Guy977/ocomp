#include <iostream>
#include <algorithm>
#include <vector>
#include <tuple>
#include <cstdio>
using namespace std;

typedef tuple<long, long, int> coord;

int main() {
  int n;
  cin >> n;
  vector<coord> coords;
  for (int i = 0; i < n; i++) {
    long x, y;
    cin >> x >> y;
    coords.push_back({ x, y, i });
  }
  sort(
    coords.begin(),
    coords.end(),
    [](coord a, coord b) {
      long distA = get<0>(a) * get<0>(a) + get<1>(a) * get<1>(a);
      long distB = get<0>(b) * get<0>(b) + get<1>(b) * get<1>(b);
      if (distA != distB) return distA < distB;
      return get<2>(a) < get<2>(b);
    }
  );
  for (coord coord : coords) {
    printf("(%ld, %ld)\n", get<0>(coord), get<1>(coord));
  }
  return 0;
}
