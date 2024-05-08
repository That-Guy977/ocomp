#include <iostream>
#include <algorithm>
#include <vector>
#include <deque>
#include <map>
#include <set>
#include <string>
#define iter(c) c.begin(), c.end()

using namespace std;

int main() {
  int n;
  string craw, praw;
  cin >> n >> craw >> praw;
  map<char, deque<short>> c;
  map<char, int> pc;
  map<short, char> pm;
  map<char, deque<short>> free;
  for (int i = 0; i < n; i++) {
    if (craw[i] != praw[i]) {
      if (craw[i] != '-') {
        c[craw[i]].push_back(i + 1);
      }
      if (praw[i] != '-') {
        if (craw[i] != '-') {
          pm[i + 1] = praw[i];
          pc[praw[i]]++;
        } else {
          free[praw[i]].push_back(i + 1);
        }
      }
    }
  }
  int actions = 0;
  for (auto [f, bs] : c) {
    actions += 3;
    if (bs.size() > pc[f]) {
      actions += bs.size() - pc[f];
    }
  }
  cout << actions << endl;
  char hold = 0;
  while (any_of(iter(c), [](const pair<char, deque<short>>& entry) {
    return !entry.second.empty();
  })) {
    if (!hold) {
      char mxk = 0;
      for (auto [f, bs] : c) {
        if (!free[f].empty() && (!mxk || bs.size() > c[mxk].size())) {
          mxk = f;
        }
      }
      int b = free[mxk].front();
      free[mxk].pop_front();
      hold = mxk;
      cout << "DRIVE " << b << endl;
      cout << "PICKUP" << endl;
    }
    int b = c[hold].front();
    c[hold].pop_front();
    cout << "DRIVE " << b << endl;
    cout << "DROPOFF" << endl;
    if (pm.count(b)) {
      if (!c[pm[b]].empty()) {
        cout << "PICKUP" << endl;
        hold = pm[b];
      }
      pm.erase(b);
    } else {
      hold = 0;
    }
  }
  return 0;
}
