#include <iostream>
#include <functional>
#include <set>

using namespace std;

int main() {
  int w, h, m, n;
  cin >> w >> h >> m >> n;
  int prev = 0;
  multiset<int, greater<int>> ws;
  for (int i = 0; i < m; i++) {
    int x;
    cin >> x;
    ws.insert(x - prev);
    prev = x;
  }
  ws.insert(w - prev);
  int mxw = *ws.begin();
  int mxnw = *++ws.begin();
  prev = 0;
  multiset<int, greater<int>> hs;
  for (int i = 0; i < n; i++) {
    int y;
    cin >> y;
    hs.insert(y - prev);
    prev = y;
  }
  hs.insert(h - prev);
  int mxh = *hs.begin();
  int mxnh = *++hs.begin();
  multiset<int, greater<int>> s { mxw * mxh, mxw * mxnh, mxnw * mxh };
  int mx = *s.begin();
  int mxn = *++s.begin();
  cout << mx << " " << mxn << endl;
  return 0;
}
