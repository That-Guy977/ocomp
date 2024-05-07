#include <iostream>
#include <vector>
using namespace std;

void fill(int, vector<vector<int>>&, int, int);

int main() {
  int n;
  cin >> n;
  vector<vector<int>> map;
  for (int i = 0; i < n; i++) {
    map.push_back({});
    for (int j = 0; j < n; j++) {
      int cell;
      cin >> cell;
      map[i].push_back(cell);
    }
  }
  int islandCount = 0;
  for (int i = 0; i < n; i++) {
    for (int j = 0; j < n; j++) {
      if (map[i][j] != 1) continue;
      fill(n, map, j, i);
      islandCount++;
    }
  }
  cout << islandCount << endl;
  return 0;
}

void fill(int n, vector<vector<int>>& map, int x, int y) {
  map[y][x] = 2;
  for (int i = -1; i <= 1; i++) {
    for (int j = -1; j <= 1; j++) {
      int nextX = x + j;
      int nextY = y + i;
      if (nextX < 0 || nextX >= n || nextY < 0 || nextY >= n) continue;
      if (map[nextY][nextX] != 1) continue;
      fill(n, map, nextX, nextY);
    }
  }
}
