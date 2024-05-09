#include <iostream>
#include <algorithm>
#include <iterator>
#include <functional>
#include <vector>
#include <set>
#include <string>
#include <cmath>
#define iter(c) c.begin(), c.end()

using namespace std;

int main() {
  int n, k;
  cin >> n >> k;
  int b[n];
  vector<set<int>> path;
  for (int i = 0; i < k; i++) {
    path.emplace_back();
  }
  for (int i = 0; i < n; i++) {
    cin >> b[i];
    b[i]--;
    path[b[i]].insert(i);
  }
  long s[k];
  for (int i = 0; i < k; i++) {
    string sraw;
    cin >> sraw;
    s[i] = 0;
    for (int j = 0; j < k; j++) {
      if (sraw[j] == '1') {
        s[i] |= 1l << j;
      }
    }
  }
  vector<set<int>> bgraph;
  for (int i = 0; i < k; i++) {
    bgraph.emplace_back();
    for (int j = 0; j < k; j++) {
      if (s[i] & 1 << j) {
        bgraph[i].insert(iter(path[j]));
      }
    }
  }
  unsigned long dist[n];
  set<int, function<bool(int, int)>> unvisited([&dist](int a, int b) {
      return dist[a] != dist[b] ? dist[a] < dist[b] : a < b;
  });
  for (int i = 0; i < n; i++) {
    dist[i] = i ? -1 : 0;
    unvisited.insert(i);
  }
  int node = 0;
  while (node != n - 1 && dist[node] != -1) {
    unvisited.erase(node);
    for (int p : bgraph[b[node]]) {
      if (!unvisited.count(p)) continue;
      int t = dist[node] + abs(node - p);
      if (t < dist[p]) {
        unvisited.erase(p);
        dist[p] = t;
        unvisited.insert(p);
      }
    }
    node = *unvisited.begin();
  }
  cout << (int)dist[n - 1] << endl;
  return 0;
}
