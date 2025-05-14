#include <iostream>
#include <algorithm>
#include <vector>
#include <deque>
#include <set>
#define iter(c) c.begin(), c.end()

using namespace std;

int main() {
  int n, w, l;
  cin >> n >> w >> l;
  vector<set<int>> b;
  for (int i = 0; i < n; i++) {
    int k;
    cin >> k;
    set<int> h;
    for (int j = 0; j < k; j++) {
      int p;
      cin >> p;
      p--;
      h.insert(p);
    }
    b.push_back(h);
  }
  int end = max(w - l * 2, 1);
  deque<set<int>> range;
  vector<int> holes(n, 0);
  bool valid = 0;
  for (int i = 0; i < end; i++) {
    while (range.size() < l * 2 + 1 && i + range.size() < w) {
      set<int> h;
      for (int j = 0; j < n; j++) {
        if (b[j].count(i + range.size())) {
          holes[j]++;
          h.insert(j);
        }
      }
      range.push_back(h);
    }
    if (all_of(iter(holes), [](int h) { return h > 0; })) {
      valid = true;
      break;
    }
    for (int h : range.front()) {
      holes[h]--;
    }
    range.pop_front();
  }
  cout << valid << endl;
  return 0;
}
