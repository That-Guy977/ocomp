#include <iostream>
#include <stack>
#include <queue>

using namespace std;

int main() {
  int t;
  cin >> t;
  for (int ti = 0; ti < t; ti++) {
    int n;
    cin >> n;
    stack<char> s;
    queue<char> q;
    priority_queue<char> pq;
    int check = 7;
    for (int i = 0; i < n; i++) {
      int op, x;
      cin >> op >> x;
      switch (op) {
        case 1:
          if (check & 1) s.push(x);
          if (check & 2) q.push(x);
          if (check & 4) pq.push(x);
          break;
        case 2:
          if (check & 1) {
            if (s.empty() || x != s.top()) {
              check &= ~1;
            }
            if (!s.empty()) s.pop();
          }
          if (check & 2) {
            if (q.empty() || x != q.front()) {
              check &= ~2;
            }
            if (!q.empty()) q.pop();
          }
          if (check & 4) {
            if (pq.empty() || x != pq.top()) {
              check &= ~4;
            }
            if (!pq.empty()) pq.pop();
          }
          break;
      }
    }
    switch (check) {
      case 0:
        cout << "impossible" << endl;
        break;
      case 1:
        cout << "stack" << endl;
        break;
      case 2:
        cout << "queue" << endl;
        break;
      case 4:
        cout << "priority queue" << endl;
        break;
      default:
        cout << "not sure" << endl;
        break;
    }
  }
  return 0;
}
