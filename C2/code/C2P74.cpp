#include <iostream>
#include <vector>
#include <set>

using namespace std;

bool bySize(const set<int>& a, const set<int>& b) {
  return a.size() < b.size();
}

int main() {
  int n;
  cin >> n;
  set<int> tambon;
  for (int i = 0; i < n; i++) {
    int x;
    cin >> x;
    tambon.insert(x);
  }
  vector<vector<int>> neighborhoods {};
  int prev = -1;
  for (const int &address : tambon) {
    if (address != prev + 1) {
      neighborhoods.emplace_back();
    }
    neighborhoods.back().push_back(address);
    prev = address;
  }
  vector<int> &largest = neighborhoods[0];
  for (vector<int> &neighborhood : neighborhoods) {
    if (neighborhood.size() > largest.size()) {
      largest = neighborhood;
    }
  }
  cout << largest.size() << endl;
  cout << largest.front() << " " << largest.back() << endl;
  return 0;
}
