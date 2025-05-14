#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;

int main() {
  int n;
  cin >> n;
  int sum = 0;
  vector<int> v;
  for (int i = 0; i < n; i++) {
    int a, b;
    cin >> a >> b;
    int x = max(a, b);
    sum += x;
    v.push_back(x);
  }
  if (n != 1) {
    for (int i = 0; i < n; i++) {
      if (i) cout << " + ";
      cout << v[i];
    }
    cout << " = ";
  }
  cout << sum << endl;
  return 0;
}
