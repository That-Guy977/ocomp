#include <iostream>
#include <algorithm>
#include <vector>
#include <queue>

using namespace std;

int main() {
  int n, l;
  cin >> n >> l;
  vector<int> h;
  for (int i = 0; i < n; i++) {
    int x;
    cin >> x;
    h.push_back(x);
  }
  queue<int> a;
  for (int i = 0; i < l; i++) {
    int p;
    cin >> p;
    p--;
    a.push(p);
  }
  int mxh = -1;
  for (int i = 0; i < n && !a.empty(); i++) {
    if (a.front() == i) {
      cout << max(mxh - h[i] + 1, 0) << endl;
      a.pop();
    }
    if (h[i] > mxh) mxh = h[i];
  }
  return 0;
}
