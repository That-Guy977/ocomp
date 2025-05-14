#include <iostream>
#include <algorithm>
#include <map>
#include <tuple>
#define iter(c) c.begin(), c.end()

using namespace std;

int main() {
  int n;
  cin >> n;
  map<int, int> count;
  for (int i = 0; i < n; i++) {
    int s;
    cin >> s;
    count[s]++;
  }
  cout << max_element(iter(count), [](pair<int, int> a, pair<int, int> b) { return a.second < b.second; })->second << endl;
  return 0;
}
