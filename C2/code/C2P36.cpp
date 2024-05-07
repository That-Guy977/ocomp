#include <iostream>
#include <algorithm>
#include <vector>
#include <set>
#include <tuple>

using namespace std;

int main() {
  int n;
  cin >> n;
  int graph[n][n];
  for (int i = 0; i < n; i++) {
    for (int j = 0; j < n; j++) {
      cin >> graph[i][j];
    }
  }
  int weight = 0;
  set<int> tree { 0 };
  vector<pair<int, int>> candidates;
  for (int i = 0; i < n; i++) {
    if (graph[0][i]) {
      candidates.emplace_back(graph[0][i], i);
    }
  }
  while (tree.size() < n) {
    pair<int, int> mn;
    for (const pair<int, int> &candidate : candidates) {
      if (!mn.first || candidate.first < mn.first) mn = candidate;
    }
    tree.insert(mn.second);
    weight += mn.first;
    candidates.erase(
      remove_if(candidates.begin(), candidates.end(), [mn](const pair<int, int> &edge) {
        return edge.second == mn.second;
      }),
      candidates.end()
    );
    for (int i = 0; i < n; i++) {
      if (graph[mn.second][i] && !tree.count(i)) {
        candidates.emplace_back(graph[mn.second][i], i);
      }
    }
  }
  cout << weight << endl;
  return 0;
}
