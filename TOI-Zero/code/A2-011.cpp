#include <iostream>
#include <set>

using namespace std;

int main() {
  set<int> found;
  for (int i = 0; i < 10; i++) {
    int n;
    cin >> n;
    if (!found.count(n)) {
      if (i) cout << " ";
      cout << n;
      found.insert(n);
    }
  }
  cout << endl;
  return 0;
}
