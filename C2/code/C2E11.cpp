#include <iostream>
#include <stack>
#include <tuple>

using namespace std;

int main() {
  int n, m;
  string necklace;
  cin >> n >> m >> necklace;
  stack<pair<int, char>> actions;
  for (int i = 0; i < m; i++) {
    char op;
    cin >> op;
    char c;
    int j;
    switch (op) {
      case 'a':
        cin >> c >> j;
        actions.emplace(j, c);
        break;
      case 'u':
        cin >> j;
        for (int ji = 0; ji < j && !actions.empty(); ji++) {
          actions.pop();
        }
        break;
    }
  }
  bool check[m];
  for (int i = 0; i < m; i++) {
    check[i] = 0;
  }
  while (!actions.empty()) {
    pair<int, char> &action = actions.top();
    actions.pop();
    if (!check[action.first]) {
      necklace[action.first] = action.second;
      check[action.first] = true;
    }
  }
  cout << necklace << endl;
  return 0;
}
