#include <iostream>
#include <queue>
#include <utility>
using namespace std;

int main() {
  int n;
  pair<int, int> start, target;
  cin >> n
  >> start.first >> start.second
  >> target.first >> target.second;
  queue<pair<int, int>> search;
  search.push(start);
  int board[n][n];
  for (int i = 0; i < n; i++) {
    for (int j = 0; j < n; j++) {
      pair<int, int> position = { j, i };
      board[i][j] = position == start ? 0 : -1;
    }
  }
  pair<int, int> moves[] = {
    {  1,  2 },
    {  2,  1 },
    {  1, -2 },
    {  2, -1 },
    { -1,  2 },
    { -2,  1 },
    { -1, -2 },
    { -2, -1 }
  };
  while (!search.empty()) {
    pair<int, int> next = search.front();
    for (pair<int, int> move : moves) {
      int nextX = next.first + move.first;
      int nextY = next.second + move.second;
      if (nextX < 0 || nextX >= n || nextY < 0 || nextY >= n) continue;
      if (board[nextY][nextX] != -1) continue;
      board[nextY][nextX] = board[next.second][next.first] + 1;
      pair<int, int> nextPos = { nextX, nextY };
      if (nextPos == target) break;
      search.push(nextPos);
    }
    search.pop();
  }
  cout << board[target.second][target.first] << endl;
  return 0;
}
