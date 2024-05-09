#include <iostream>
#include <vector>
#include <map>
#include <set>
#include <tuple>
#include <cmath>
#define EPSILON 0.0001

using namespace std;

struct epsilondouble {
  double value;

  epsilondouble(double value): value(value) {}

  bool operator==(const epsilondouble& other) const {
    return abs(value - other.value) < EPSILON;
  }
  bool operator!=(const epsilondouble& other) const {
    return !(*this == other);
  }
  bool operator<(const epsilondouble& other) const {
    if (*this == other) return 0;
    return value < other.value;
  }
};

struct pvec {
  epsilondouble r, theta;

  pvec(double r, double theta): r(r), theta(theta) {
    if (theta < 0) this->theta.value += 180;
  }

  bool operator==(const pvec& other) const {
    return r == other.r && theta == other.theta;
  }
  bool operator<(const pvec& other) const {
    if (r != other.r) return r < other.r;
    return theta < other.theta;
  }
};

int main() {
  int n;
  cin >> n;
  vector<pair<int, int>> plot;
  for (int i = 0; i < n; i++) {
    int x, y;
    cin >> x >> y;
    plot.emplace_back(x, y);
  }
  map<pvec, int> edges;
  int count = 0;
  for (int i = 0; i < n; i++) {
    for (int j = i + 1; j < n; j++) {
      auto [x1, y1] = plot[i];
      auto [x2, y2] = plot[j];
      count += edges[{ hypot(x1 - x2, y1 - y2), atan2(y1 - y2, x1 - x2) }]++;
    }
  }
  cout << count / 2 << endl;
  for (auto [v, c] : edges) {
    cout << "(" << v.r.value << ", " << v.theta.value << "): " << c << endl;
  }
  return 0;
}
