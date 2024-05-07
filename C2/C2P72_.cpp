#include <iostream>
#include <algorithm>
#include <vector>
#include <tuple>

using namespace std;

struct point {
  int idx;
  int val;
  point(int idx, int val): idx{idx}, val{val} {}
};

typedef vector<point>::iterator point_iter;
typedef vector<point>::reverse_iterator point_riter;

bool byPointIndex(point a, point b) {
  return a.idx < b.idx;
}

bool byRPointIndex(point a, point b) {
  return a.idx > b.idx;
}

int main() {
  int n;
  cin >> n;
  vector<point> peaks, dips;
  int prev = -1;
  int pprev = -1;
  cin >> prev;
  for (int i = 1; i < n; i++) {
    int x;
    cin >> x;
    if (prev > x && (i == 1 || prev >= pprev)) peaks.emplace_back(i - 1, prev);
    if (prev < x && (i == 1 || prev <= pprev)) dips.emplace_back(i - 1, prev);
    pprev = prev;
    prev = x;
  }
  if (prev > pprev) peaks.emplace_back(n - 1, prev);
  if (prev < pprev) dips.emplace_back(n - 1, prev);
  int max = 0;
  point_iter dipA = dips.begin();
  for (; dipA != dips.end(); ++dipA) {
    point_iter peakA = upper_bound(peaks.begin(), peaks.end(), *dipA, byPointIndex);
    for (; peakA != peaks.end(); ++peakA) {
      int profitA = peakA->val - dipA->val;
      if (profitA > max) max = profitA;
      point_iter dipB = upper_bound(dipA, dips.end(), *peakA, byPointIndex);
      for (; dipB != dips.end(); ++dipB) {
        point_iter peakB = upper_bound(peakA, peaks.end(), *dipB, byPointIndex);
        for (; peakB != peaks.end(); ++peakB) {
          int profitB = peakB->val - dipB->val;
          int profit = profitA + profitB;
          if (profit > max) max = profit;
        }
      }
    }
  }
  cout << max << endl;
  return 0;
}
