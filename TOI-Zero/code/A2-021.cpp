#include <iostream>
#include <algorithm>
#include <vector>
#define iter(c) c.begin(), c.end()

using namespace std;

int main() {
  int n, k;
  cin >> n >> k;
  vector<int> a1;
  for (int i = 0; i < n; i++) {
    int x;
    cin >> x;
    a1.push_back(x);
  }
  sort(iter(a1));
  vector<int> a2;
  for (int i = 0; i < n; i++) {
    int x;
    cin >> x;
    a2.push_back(x);
  }
  sort(iter(a2));
  vector<int> b1;
  for (int i = 0; i < n; i++) {
    int x;
    cin >> x;
    b1.push_back(x);
  }
  sort(iter(b1));
  vector<int> b2;
  for (int i = 0; i < n; i++) {
    int x;
    cin >> x;
    b2.push_back(x);
  }
  sort(iter(b2));
  int mx1 = 0;
  int mx2 = 0;
  for (int i = 0; i < n; i++) {
    int t1 = a1[i] + b1[n - i - 1];
    if (t1 > mx1) mx1 = t1;
    int t2 = a2[i] + b2[n - i - 1];
    if (t2 > mx2) mx2 = t2;
  }
  while (a1.size() + a2.size() > k) {
    if (mx1 > mx2) {
      a1.pop_back();
      b1.pop_back();
      mx1 = 0;
      for (int i = 0; i < a1.size(); i++) {
        int t = a1[i] + b1[a1.size() - i - 1];
        if (t > mx1) mx1 = t;
      }
    } else {
      a2.pop_back();
      b2.pop_back();
      mx2 = 0;
      for (int i = 0; i < a2.size(); i++) {
        int t = a2[i] + b2[a2.size() - i - 1];
        if (t > mx2) mx2 = t;
      }
    }
  }
  cout << max(mx1, mx2) << endl;
  return 0;
}
