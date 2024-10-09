#include <iostream>
#include <iomanip>
#include <set>

using namespace std;

int main() {
  int n;
  cin >> n;
  cout << fixed << setprecision(1);
  multiset<int> a;
  {
    int x;
    cin >> x;
    cout << (double)x << endl;
    a.insert(x);
  }
  multiset<int>::iterator l = a.begin(), r = a.begin();
  for (int i = 1; i < n; i++) {
    int x;
    cin >> x;
    a.insert(x);
    if (i % 2) {
      if (x >= *l) {
        ++r;
      } else {
        --l;
      }
    } else {
      if (x >= *l) {
        ++l;
      }
      if (x < *r) {
        --r;
      }
    }
    cout << (*l + *r) / 2.0 << endl;
  }
  return 0;
}
