#include <iostream>
#include <map>

using namespace std;

int main() {
  int n, m;
  cin >> n >> m;
  map<int, int> delta;
  for (int i = 0; i < m; i++) {
    int s, t;
    cin >> s >> t;
    delta[s]++;
    delta[t + 1]--;
  }
  int mx = 0;
  int curr = 0;
  for (auto [pos, d] : delta) {
    curr += d;
    if (curr > mx) mx = curr;
  }
  cout << mx << endl;
  return 0;
}
