#include <iostream>
#include <algorithm>
#include <vector>
#include <deque>
#include <map>
#include <string>
#define iter(c) c.begin(), c.end()

using namespace std;

int main() {
  int n;
  string craw, praw;
  cin >> n >> craw >> praw;
  map<char, deque<short>> c;
  map<short, char> p;
  map<char, deque<short>> fr;
  for (int i = 0; i < n; i++) {
    if (craw[i] != praw[i]) {
      if (craw[i] != '-') {
        if (praw[i] != '-') {
          c[craw[i]].push_front(i + 1);
        } else {
          c[craw[i]].push_back(i + 1);
        }
      }
      if (praw[i] != '-') {
        if (craw[i] != '-') {
          p[i + 1] = praw[i];
        } else {
          fr[praw[i]].push_back(i + 1);
        }
      }
    }
  }
  vector<short> actions;
  char hold = 0;
  while (any_of(iter(c), [](const pair<char, deque<short>>& entry) {
    return !entry.second.empty();
  })) {
    if (!hold) {
      char mxk = 0;
      for (auto [f, bs] : c) {
        if (!fr[f].empty() && (!mxk || bs.size() > c[mxk].size())) {
          mxk = f;
        }
      }
      hold = mxk;
      actions.push_back(fr[mxk].front());
      actions.push_back(0);
      fr[mxk].pop_front();
    }
    int b = c[hold].front();
    actions.push_back(b);
    actions.push_back(-1);
    c[hold].pop_front();
    if (p.count(b)) {
      if (!c[p[b]].empty()) {
        actions.push_back(0);
        hold = p[b];
      }
      p.erase(b);
    } else {
      hold = 0;
    }
  }
  cout << actions.size() << endl;
  for (int action : actions) {
    switch (action) {
      case 0:
        cout << "PICKUP" << endl;
        break;
      case -1:
        cout << "DROPOFF" << endl;
        break;
      default:
        cout << "DRIVE " << action << endl;
        break;
    }
  }
  return 0;
}
