#include <iostream>
#include <iterator>
#include <set>

using namespace std;

int main() {
  int t;
  cin >> t;
  for (int ti = 0; ti < t; ti++) {
    int n;
    cin >> n;
    multiset<int> box;
    int cost = 0;
    for (int i = 0; i < n; i++) {
      int k;
      cin >> k;
      for (int j = 0; j < k; j++) {
        int x;
        cin >> x;
        box.insert(x);
      }
      multiset<int>::iterator begin = box.begin();
      multiset<int>::iterator end = prev(box.end());
      cost += *end - *begin;
      box.erase(begin);
      box.erase(end);
    }
    cout << cost << endl;
  }
  return 0;
}
