#include <iostream>
#include <algorithm>
#include <vector>
#define iter(c) c.begin(), c.end()

using namespace std;

int main() {
  int n;
  cin >> n;
  vector<int> v;
  for (int i = 0; i < n; i++) {
    int x;
    cin >> x;
    v.push_back(x);
  }
  cout << *min_element(iter(v)) << endl;
  return 0;
}
