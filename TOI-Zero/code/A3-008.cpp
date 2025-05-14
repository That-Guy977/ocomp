#include <iostream>
#include <vector>
#include <map>

using namespace std;

int main() {
  int n, k;
  cin >> n >> k;
  vector<int> c;
  for (int i = 0; i < n; i++) {
    int x;
    cin >> x;
    c.push_back(x);
  }
  long count = 0;
  int end = -1;
  map<int, int> range;
  while (range.size() < k) {
    range[c[++end]]++;
  }
  range[c[0]]--;
  count += n - end;
  for (int i = 1; i < n; i++) {
    if (range[c[i - 1]] == 0) {
      while (end < n) {
        range[c[++end]]++;
        if (range[c[end]] == 1) break;
      }
    }
    count += n - end;
    range[c[i]]--;
  }
  cout << count << endl;
  return 0;
}
