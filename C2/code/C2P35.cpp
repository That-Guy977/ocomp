#include <iostream>
#include <vector>
#include <set>
#include <tuple>

using namespace std;

int moveX[] { +1, +1, +1, -1, -1, -1,  0,  0 };
int moveY[] { +1, -1,  0, +1, -1,  0, +1, -1 };

int main() {
  int n, m;
  cin >> n >> m;
  vector<vector<bool>> map;
  for (int i = 0; i < n; i++) {
    map.emplace_back();
    for (int j = 0; j < m; j++) {
      char tile;
      cin >> tile;
      map[i].push_back(tile == 'W');
    }
  }
  int k;
  cin >> k;
  for (int ki = 0; ki < k; ki++) {
    int i, j;
    cin >> i >> j;
    vector<pair<int, int>> searchlist { { j - 1, i - 1 } };
    set<pair<int, int>> visited;
    while (!searchlist.empty()) {
      set<pair<int, int>> next;
      for (pair<int, int> &tile : searchlist) {
        if (visited.count(tile)) continue;
        visited.insert(tile);
        for (int move = 0; move < 8; move++) {
          pair<int, int> nextTile = tile;
          nextTile.first += moveX[move];
          nextTile.second += moveY[move];
          if (
            nextTile.first >= 0 && nextTile.first < m
            && nextTile.second >= 0 && nextTile.second < n
            && map[nextTile.second][nextTile.first]
          ) {
            next.insert(nextTile);
          }
        }
      }
      searchlist.clear();
      searchlist.insert(searchlist.end(), next.begin(), next.end());
    }
    cout << visited.size() << endl;
  }
  return 0;
}
