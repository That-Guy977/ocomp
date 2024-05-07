#include <iostream>
#include <vector>
#include <map>
#include <set>
#include <deque>

using namespace std;

int main() {
  int n, s, t;
  cin >> n >> s >> t;
  map<int, int> heights;
  map<int, vector<int>> graph;
  for (int i = 0; i < n; i++) {
    int id, h, m;
    cin >> id >> h >> m;
    heights[id] = h;
    for (int j = 0; j < m; j++) {
      int x;
      cin >> x;
      graph[id].push_back(x);
    }
  }
  map<int, int> times;
  set<int> unvisited;
  for (int i = 0; i < n; i++) {
    times[i] = -1;
    unvisited.insert(i);
  }
  times[s] = 0;
  while (!unvisited.empty()) {
    int current = -1;
    for (int node : unvisited) {
      if (times[node] != -1 && (current == -1 || times[node] < times[current])) current = node;
    }
    if (current == -1) break;
    unvisited.erase(current);
    for (const int &neighbor : graph[current]) {
      if (unvisited.count(neighbor) && heights[current] > heights[neighbor]) {
        int time = times[current] + (heights[current] - heights[neighbor]);
        if (times[neighbor] == -1 || time < times[neighbor]) times[neighbor] = time;
      }
    }
  }
  cout << times[t] << endl;
  return 0;
}
