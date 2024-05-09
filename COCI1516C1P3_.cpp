#include <iostream>
#include <iterator>
#include <list>

using namespace std;

int main() {
  int n;
  cin >> n;
  list<int> b;
  for (int i = 0; i < n; i++) {
    int x;
    cin >> x;
    b.push_back(x);
  }
  int count = 0;
  while (!b.empty()) {
    int h = b.front();
    for (list<int>::iterator it = b.begin(); it != b.end(); ++it) {
      if (*it == h) {
        --it;
        b.erase(next(it));
        h--;
      }
      if (h == 0) break;
    }
    count++;
  }
  cout << count << endl;
  return 0;
}
