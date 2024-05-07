#include <iostream>
#include <algorithm>
#include <deque>
#include <map>

using namespace std;

int main() {
  int t;
  cin >> t;
  deque<pair<int, deque<int>>> queue;
  map<int, int> comp;
  for (int i = 0; i < t; i++) {
    int k;
    cin >> k;
    for (int j = 0; j < k; j++) {
      int id;
      cin >> id;
      comp[id] = i;
    }
  }
  while (true) {
    char op;
    cin >> op;
    if (op == 'S') break;
    else if (op == 'E') {
      int id;
      cin >> id;
      int school = comp[id];
      deque<pair<int, deque<int>>>::iterator subq = find_if(
        queue.begin(),
        queue.end(),
        [school](pair<int, deque<int>> &subq) {
          return subq.first == school;
        }
      );
      if (subq != queue.end()) {
        subq->second.push_back(id);
      } else {
        queue.push_back({ school, { id } });
      }
    } else if (op == 'D') {
      pair<int, deque<int>> &subq = queue.front();
      cout << subq.second.front() << endl;
      subq.second.pop_front();
      if (subq.second.empty()) {
        queue.pop_front();
      }
    }
  }
  return 0;
}
