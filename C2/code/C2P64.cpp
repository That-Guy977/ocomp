#include <iostream>
#include <set>
#include <queue>

using namespace std;

int main() {
  int t;
  cin >> t;
  for (int ti = 0; ti < t; ti++) {
    int n;
    cin >> n;
    set<int> bc;
    queue<int> b;
    int mxb = 0;
    for (int i = 0; i < n; i++) {
      int x;
      cin >> x;
      if (bc.count(x)) {
        while (b.front() != x) {
          bc.erase(b.front());
          b.pop();
        }
        b.pop();
      } else {
        bc.insert(x);
      }
      b.push(x);
      if (b.size() > mxb) mxb = b.size();
    }
    cout << mxb << endl;
  }
  return 0;
}
