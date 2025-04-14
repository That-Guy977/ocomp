#include <iostream>
#include <vector>
#include <set>
#include <tuple>

using namespace std;

int main() {
  int t;
  cin >> t;
  for (int ti = 0; ti < t; ti++) {
    int n;
    cin >> n;
    multiset<pair<int, int>> events;
    for (int i = 0; i < n; i++) {
      int s, e;
      cin >> s >> e;
      events.emplace(s, e);
    }
    vector<int> fields;
    for (auto [s, e] : events) {
      for (int& field : fields) {
        if (s >= field) {
          field = e;
          goto next;
        }
      }
      fields.push_back(e);
      next:;
    }
    cout << fields.size() << endl;
  }
  return 0;
}
