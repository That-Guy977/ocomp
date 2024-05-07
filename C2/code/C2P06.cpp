#include <iostream>
#include <queue>
using namespace std;

int main() {
  int n, m;
  cin >> n >> m;
  priority_queue<int> booths, offers;
  for (int i = 0; i < n; i++) {
    int x;
    cin >> x;
    booths.push(x);
  }
  for (int i = 0; i < m; i++) {
    int y;
    cin >> y;
    offers.push(y);
  }
  int total = 0;
  while (!booths.empty() && !offers.empty()) {
    if (booths.top() <= offers.top()) {
      total += offers.top();
      offers.pop();
    }
    booths.pop();
  }
  cout << total << endl;
  return 0;
}
