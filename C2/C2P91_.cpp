#include <iostream>
#include <algorithm>
#include <map>

using namespace std;

typedef map<int, int>::iterator memory_it;

int main() {
  int n, m;
  cin >> n >> m;
  map<int, int> memory;
  for (int i = 0; i < m; i++) {
    int p, s;
    cin >> p >> s;
    memory_it begin = memory.begin();
    memory_it end = memory.end();
    memory_it nxt = lower_bound(begin, end, pair<const int, int> { p, 0 });
    int pos = p;
    if (nxt != begin) {
      --nxt;
      if (pos < nxt->first + nxt->second) {
        pos = nxt->first + nxt->second;
      }
      ++nxt;
    }
    while (nxt != end && nxt->first < pos + s) {
      pos = nxt->first + nxt->second;
      ++nxt;
    }
    if (nxt == end) {
      if (pos + s - 1 > n) {
        pos = 1;
        nxt = begin;
        while (pos < p && nxt->first < pos + s) {
          pos = nxt->first + nxt->second;
          ++nxt;
        }
        if (pos >= p) pos = -1;
      }
    }
    if (pos != -1) {
      memory[pos] = s;
      cout << pos << " " << pos + s - 1 << endl;
    } else {
      cout << "invalid" << endl;
    }
  }
  return 0;
}
