#include <iostream>
#include <algorithm>
#include <vector>
#include <map>
#define iter(c) c.begin(), c.end()

using namespace std;

int main() {
  int n, m;
  cin >> n >> m;
  map<int, vector<vector<int>>> rules;
  vector<bool> lit(n, false);
  lit[0] = true;
  for (int i = 0; i < m; i++) {
    int k;
    cin >> k;
    vector<int> rule;
    for (int j = 0; j < k; j++) {
      int s;
      cin >> s;
      rule.push_back(s - 1);
    }
    int t;
    cin >> t;
    rules[t - 1].push_back(rule);
  }
  while (true) {
    vector<int> newlit;
    for (const auto& [t, rs] : rules) {
      if (any_of(
        iter(rs),
        [&](const vector<int>& r) {
          return all_of(iter(r), [&](int s) { return lit[s]; });
        }
      )) {
        newlit.push_back(t);
      }
    }
    if (newlit.empty()) break;
    for (int t : newlit) {
      rules.erase(t);
      lit[t] = true;
    }
  }
  cout << count(iter(lit), true) << endl;
  return 0;
}
