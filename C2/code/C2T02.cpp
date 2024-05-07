#include <iostream>
#include <functional>
#include <vector>
#include <set>
#include <queue>
#include <tuple>

using namespace std;

typedef pair<int, string> patient;

int main() {
  int n, k;
  cin >> n >> k;
  priority_queue<
    patient,
    vector<patient>,
    function<bool(patient, patient)>
  > waiting{ [](patient a, patient b) { return a.first > b.first; } };
  vector<vector<string>> rooms;
  for (int i = 0; i < k; i++) {
    rooms.emplace_back();
  }
  for (int i = 0; i < n; i++) {
    char op;
    cin >> op;
    int code, f, p, l;
    string name;
    switch (op) {
      case 'A':
        cin >> code >> name;
        waiting.emplace(code, name);
        break;
      case 'M':
        cin >> f >> p;
        for (int i = 0; i < f; i++) {
          rooms[p + i - 1].push_back(waiting.top().second);
          waiting.pop();
        }
        break;
      case 'R':
        cin >> l;
        rooms[l - 1].clear();
        break;
    }
  }
  set<string> remaining;
  while (!waiting.empty()) {
    remaining.insert(waiting.top().second);
    waiting.pop();
  }
  for (vector<string>& room : rooms) {
    for (string& name : room) {
      remaining.insert(name);
    }
  }
  for (const string& name : remaining) {
    cout << name << endl;
  }
  return 0;
}
