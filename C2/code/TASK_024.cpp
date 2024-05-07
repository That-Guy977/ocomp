#include <iostream>

using namespace std;

int main() {
  int n, m;
  cin >> n >> m;
  bool graph[n][n];
  for (int i = 0; i < n; i++) {
    for (int j = 0; j < n; j++) {
      graph[i][j] = false;
    }
  }
  for (int i = 0; i < m; i++) {
    int a, b;
    cin >> a >> b;
    graph[a-1][b-1] = true;
    graph[b-1][a-1] = true;
  }
  for (int i = 0; i < n; i++) {
    for (int j = 0; j < n; j++) {
      if (j) cout << " ";
      cout << graph[i][j];
    }
    cout << endl;
  }
  return 0;
}
