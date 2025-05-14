#include <iostream>
#include <algorithm>
#include <vector>
#define iter(c) c.begin(), c.end()

using namespace std;

int main() {
  int n, k;
  cin >> n >> k;
  vector<int> ls(k, 0);
  for (int i = 0; i < n; i++) {
    int l;
    cin >> l;
    l--;
    ls[l]++;
  }
  int p = *min_element(iter(ls));
  cout << n - p * k << endl;
  return 0;
}
