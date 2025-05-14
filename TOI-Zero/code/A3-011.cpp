#include <iostream>
#include <set>

using namespace std;

int main() {
  int n;
  cin >> n;
  int c[n + 1];
  c[0] = 0;
  cin >> c[1];
  for (int i = 2; i <= n; i++) {
    cin >> c[i];
    c[i] += c[i - 1];
  }
  set<int> p;
  for (int i = 1; i <= n; i++) {
    for (int j = 0; j < i; j++) {
      p.insert(c[i] - c[j]);
    }
  }
  cout << p.size() << endl;
  return 0;
}
