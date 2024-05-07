#include <iostream>
#include <functional>
#include <queue>

using namespace std;

int main() {
  int n;
  cin >> n;
  priority_queue<int, vector<int>, greater<int>> addends;
  for (int i = 0; i < n; i++) {
    int x;
    cin >> x;
    addends.push(x);
  }
  long cost = 0;
  while (addends.size() > 1) {
    int a = addends.top();
    addends.pop();
    int b = addends.top();
    addends.pop();
    int r = a + b;
    addends.push(r);
    cost += r;
  }
  cout << cost << endl;
  return 0;
}
