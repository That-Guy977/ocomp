#include <iostream>
#include <set>
#include <tuple>

using namespace std;

int root(pair<int, int>[], int);

int main() {
  int n, k;
  cin >> n >> k;
  pair<int, int> network[n];
  for (int i = 0; i < n; i++) {
    network[i] = { i, 0 };
  }
  set<pair<int, pair<int, int>>> pipes;
  for (int i = 0; i < k; i++) {
    int s, t, d;
    cin >> s >> t >> d;
    pipes.emplace(d, pair{ s, t });
  }
  int cost = 0;
  int roots = n;
  while (roots > 1 && !pipes.empty()) {
    auto [d, e] = *pipes.begin();
    auto [s, t] = e;
    pipes.erase(pipes.begin());
    int sr = root(network, network[s].first);
    int tr = root(network, network[t].first);
    if (sr != tr) {
      cost += d;
      network[tr].first = sr;
      network[s].second++;
      network[t].second++;
      roots--;
    }
  }
  if (roots > 1) {
    cout << -1 << endl;
  } else {
    cout << cost << endl;
    int ends = 0;
    for (auto [_r, c] : network) {
      if (c == 1) ends++;
    }
    cout << ends << endl;
  }
  return 0;
}

int root(pair<int, int> network[], int n) {
  if (network[n].first == n) return n;
  return network[n].first = root(network, network[network[n].first].first);
}
