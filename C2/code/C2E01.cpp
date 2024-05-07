#include <iostream>
#include <functional>
#include <queue>

using namespace std;

int main() {
  int n, k;
  cin >> n >> k;
  priority_queue<int, vector<int>, greater<int>> corn;
  for (int i = 0; i < n; i++) {
    int s;
    cin >> s;
    if (corn.size() < k) {
      corn.push(s);
    } else if (corn.top() < s) {
      corn.push(s);
      corn.pop();
    }
    cout << corn.top() << endl;
  }
  return 0;
}
