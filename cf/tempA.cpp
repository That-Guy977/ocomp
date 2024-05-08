#include <iostream>
#include <vector>
#include <tuple>
#include <cmath>
#define EPSILON 0.0001

using namespace std;

struct point {
  int x, y;

  point(int x, int y): x(x), y(y) {}

  bool operator<(const point& other) const {
    return x != other.x ? x < x : y < y;
  }
};

struct pvec {
  double r, theta;

  pvec(double r, double theta): r(r), theta(theta) {};

  bool operator==(const pvec& other) const {
    if (abs(r - other.r) < EPSILON && abs(theta - other.theta) < EPSILON) {
      cout << "cmpeq " << r << "-" << other.r << "=" << r - other.r << endl;
      cout << "cmpeq " << theta << "-" << other.theta << "=" << theta - other.theta << endl;
    }
    return abs(r - other.r) < EPSILON && abs(theta - other.theta) < EPSILON;
  }
};

int main() {
  int n;
  cin >> n;
  vector<pair<point, vector<pvec>>> plot;
  for (int i = 0; i < n; i++) {
    int x, y;
    cin >> x >> y;
    plot.push_back({ { x, y }, {} });
  }
  for (int i = 0; i < n; i++) {
    for (int j = i + 1; j < n; j++) {
      auto [x1, y1] = plot[i].first;
      auto [x2, y2] = plot[j].first;
      plot[i].second.emplace_back(hypot(x1 - x2, y1 - y2), atan2(y1 - y2, x1 - x2));
    }
  }
  for (int i = 0; i < n; i++) {
    cout << "(" << plot[i].first.x << ", " << plot[i].first.y << "): [";
    for (int j = 0; j < plot[i].second.size(); j++) {
      if (j) cout << ", ";
      cout << "(" << plot[i].second[j].r << ", " << plot[i].second[j].theta << ")";
    }
    cout << "]" << endl;
  }
  int count = 0;
  for (int i = 0; i < n; i++) {
    vector<pvec>& pA = plot[i].second;
    for (int j = 0; j < pA.size(); j++) {
      pvec& b = pA[j];
      for (int k = j + 1; k < pA.size(); k++) {
        vector<pvec>& pC = plot[k+i].second;
        for (int l = 0; l < pC.size(); l++) {
          pvec& d = pC[l];
          if (b == d) {
            cout << "{" << i << ", " << j << ", " << k << ", " << l << "}" << endl;
            cout << "{" << b.r << "@" << b.theta << "}, {" << d.r << "@" << d.theta << "}" << endl;
            count++;
            goto next;
          }
        }
      }
      next:;
    }
  }
  cout << count << endl;
  return 0;
}