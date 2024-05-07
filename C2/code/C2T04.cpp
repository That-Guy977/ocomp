#include <iostream>
#include <vector>

using namespace std;

int main() {
  int n;
  cin >> n;
  vector<int> ts;
  ts.reserve(n);
  for (int i = 0; i < n; i++) {
    int t;
    cin >> t;
    ts.push_back(t);
  }
  int count = -1;
  bool diff;
  do {
    diff = false;
    int prev = 10000;
    for (int i = 0; i < ts.size(); i++) {
      int v = ts[i];
      if (v == 0) continue;
      if (v > prev) {
        ts[i] = 0;
        diff = true;
      }
      prev = v;
    }
    count++;
  } while (diff);
  cout << count << endl;
  return 0;
}
