#include <iostream>
#include <algorithm>
#include <functional>
#include <vector>
#include <set>

using namespace std;

struct portfolio {
  int id, w;
  double score;
};

int main() {
  int n, m, k, h;
  cin >> n >> m >> k >> h;
  vector<portfolio> ports;
  for (int i = 0; i < n; i++) {
    int id, w;
    cin >> id >> w;
    portfolio port = { id, w };
    multiset<int, greater<int>> ps;
    for (int j = 0; j < w; j++) {
      int p;
      cin >> p;
      ps.insert(p);
    }
    double sum = 0;
    int count = min(w, k);
    int limit = count;
    for (multiset<int>::iterator it = ps.begin(); limit-- && it != ps.end(); ++it) {
      sum += *it;
    }
    port.score = sum / count;
    ports.push_back(port);
  }
  sort(
    ports.begin(),
    ports.end(),
    [](portfolio a, portfolio b) {
      if (a.score != b.score) return a.score > b.score;
      if (a.w != b.w) return a.w < b.w;
      return a.id < b.id;
    }
  );
  for (int i = 0; i < h;) {
    double score = ports[i].score;
    int w = ports[i].w;
    while (i < n && ports[i].score == score && ports[i].w == w) {
      cout << ports[i].id << endl;
      i++;
    }
  }
  return 0;
}
