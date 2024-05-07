#include <iostream>
#include <vector>
#include <map>
#include <set>
#include <tuple>

using namespace std;

struct edge {
  int w;
  int a;
  int b;
  bool operator<(const edge &other) const {
    tuple<int, int, int> tuple_this = { w, a, b };
    tuple<int, int, int> tuple_other = { other.w, other.a, other.b };
    return tuple_this < tuple_other;
  }
};

int root(map<int, int>&, int);

int main() {
  int v, e;
  cin >> v >> e;
  map<int, int> forest;
  set<edge> edges;
  for (int i = 0; i < e; i++) {
    int a, b, w;
    cin >> a >> b >> w;
    forest[a];
    forest[b];
    edges.insert({ w, a, b });
  }
  int weight = 0;
  for (const edge &edge : edges) {
    int rootA = root(forest, edge.a);
    int rootB = root(forest, edge.b);
    if (rootA != rootB) {
      forest[rootB] = rootA;
      weight += edge.w;
    }
  }
  cout << weight << endl;
  return 0;
}

int root(map<int, int> &forest, int v) {
  while (forest[v]) {
    v = forest[v];
  }
  return v;
}
