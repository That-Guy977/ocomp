#include <iostream>
#include <map>
#include <set>
#include <queue>
#include <tuple>

using namespace std;

int main() {
  set<int> primes = { 2 };
  for (int i = 3; i < 10000; i += 2) {
    for (int p : primes) {
      if (i % p == 0) goto next;
    }
    primes.insert(i);
    next:;
  }
  map<int, set<int>> graph;
  for (int p : primes) {
    if (p < 1000) continue;
    for (int e = 1; e <= 1000; e *= 10) {
      for (int k = p / e % 10; k <= 9; k++) {
        int x = p / e / 10 * e * 10 + p % e + k * e;
        if (x != p && primes.count(x)) {
          graph[p].insert(x);
          graph[x].insert(p);
        }
      }
    }
  }
  int n;
  cin >> n;
  for (int ni = 0; ni < n; ni++) {
    int a, b;
    cin >> a >> b;
    queue<pair<int, int>> search;
    search.emplace(a, 0);
    set<int> visited;
    while (!search.empty()) {
      auto [x, d] = search.front();
      search.pop();
      if (visited.count(x)) continue;
      visited.insert(x);
      if (x == b) {
        cout << d << endl;
        break;
      }
      for (int nxt : graph[x]) {
        search.emplace(nxt, d + 1);
      }
    }
  }
  return 0;
}
