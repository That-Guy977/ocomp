#include <iostream>
#include <map>
#include <set>

using namespace std;

void walk(char, map<char, set<char>>&, map<char, bool>&);

int main() {
  char maxNode;
  cin >> maxNode;
  map<char, set<char>> graph;
  while (true) {
    char a = 0, b = 0;
    cin >> a >> b;
    if (!a && !b) break;
    graph[a].insert(b);
    graph[b].insert(a);
  }
  map<char, bool> check;
  int subgraphs = 0;
  for (char i = 'A'; i <= maxNode; i++) {
    if (!check[i]) {
      walk(i, graph, check);
      subgraphs++;
    }
  }
  cout << subgraphs << endl;
  return 0;
}

void walk(char node, map<char, set<char>> &graph, map<char, bool> &check) {
  check[node] = true;
  for (char connection : graph[node]) {
    if (!check[connection]) {
      walk(connection, graph, check);
    }
  }
}
