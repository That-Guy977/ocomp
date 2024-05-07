#include <iostream>
#include <vector>
#include <tuple>
#include <algorithm>
using namespace std;

typedef pair<int, int> ticket;

int main() {
  for (int i = 0; i < 5; i++) {
    int n, c;
    cin >> n >> c;
    vector<ticket> tickets;
    for (int j = 0; j < n; j++) {
      int fan;
      cin >> fan;
      for (int k = 0; k <= tickets.size(); k++) {
        if (k < tickets.size()) {
          if (tickets[k].first == fan) {
            tickets[k].second++;
            break;
          }
        } else {
          tickets.emplace_back(fan, 1);
          break;
        }
      }
    }
    stable_sort(
      tickets.begin(),
      tickets.end(),
      [](ticket a, ticket b) {
        int ta = a.second;
        int tb = b.second;
        return ta > tb;
      }
    );
    for (int j = 0; j < tickets.size(); j++) {
      if (j) cout << " ";
      ticket& t = tickets[j];
      for (int k = 0; k < t.second; k++) {
        if (k) cout << " ";
        cout << t.first;
      }
    }
    cout << endl;
  }
  return 0;
}
