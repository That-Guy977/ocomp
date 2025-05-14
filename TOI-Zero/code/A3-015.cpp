#include <iostream>
#include <set>

using namespace std;

int main() {
  int n;
  cin >> n;
  multiset<int> l;
  for (int i = 0; i < n; i++) {
    int x;
    cin >> x;
    l.insert(x);
  }
  int total = 0;
  int currl = 0;
  for (int x : l) {
    currl += x;
    total += currl;
  }
  cout << total * 2 << endl;
  return 0;
}
