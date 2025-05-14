#include <iostream>
#include <set>
#include <map>

using namespace std;

int main() {
  int n;
  cin >> n;
  map<int, int> seq;
  for (int i = 1; i <= n; i++) {
    int t;
    cin >> t;
    seq[i] = t;
  }
  set<int> visited;
  int mxcycle = 0;
  for (int i = 1; i <= n; i++) {
    if (visited.count(i)) continue;
    int cycle = 0;
    int k = i;
    do {
      visited.insert(k);
      k = seq[k];
      cycle++;
    } while (k != i);
    if (cycle > mxcycle) mxcycle = cycle;
  }
  cout << mxcycle << endl;
  return 0;
}
