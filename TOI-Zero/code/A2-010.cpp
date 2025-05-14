#include <iostream>
#include <iterator>
#include <vector>
#include <stack>
#define riter(c) c.rbegin(), c.rend()

using namespace std;

int main() {
  int n, q;
  cin >> n >> q;
  vector<int> mxl;
  int pos = 0;
  int depth = -1;
  stack<int> steps;
  for (int i = 0; i < n; i++) {
    int d, l;
    cin >> d >> l;
    if (d > 0) {
      steps.push(pos);
    } else {
      int len = pos - steps.top();
      while (mxl.size() <= depth) mxl.push_back(0);
      if (len > mxl[depth]) mxl[depth] = len;
      steps.pop();
    }
    depth += d;
    pos += l;
  }
  mxl[depth] = pos;
  for (int i = 0; i < q; i++) {
    int l;
    cin >> l;
    cout << distance(lower_bound(riter(mxl), l), mxl.rend()) << endl;
  }
  return 0;
}
