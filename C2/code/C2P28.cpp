#include <iostream>
#include <algorithm>
#include <map>
#include <tuple>

using namespace std;

struct general {
  int id;
  int army;
  bool operator<(const general &other) const {
    if (army != other.army) return army < other.army;
    return id > other.id;
  }
};

int root(map<int, int>&, int);

int main() {
  int n, m;
  cin >> n >> m;
  map<int, int> forest;
  map<int, general> players;
  for (int i = 0; i < n; i++) {
    int x;
    cin >> x;
    forest[i + 1];
    players[i + 1] = { i + 1, x };
  }
  for (int i = 0; i < m; i++) {
    int idA, idB;
    cin >> idA >> idB;
    int rootA = root(forest, idA);
    int rootB = root(forest, idB);
    if (rootA != rootB) {
      pair<const general&, const general&> wl = minmax(players[rootA], players[rootB]);
      const general &winner = wl.second;
      const general &loser = wl.first;
      players[winner.id].army += loser.army / 2;
      forest[loser.id] = winner.id;
      cout << winner.id << endl;
    } else {
      cout << -1 << endl;
    }
  }
  return 0;
}

int root(map<int, int> &forest, int id) {
  while (forest[id]) {
    id = forest[id];
  }
  return id;
}
