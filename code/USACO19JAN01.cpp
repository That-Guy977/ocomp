#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;

int main() {
  int n;
  cin >> n;
  vector<int> paths;
  for (int i = 0; i < n; i++) {
    paths.push_back(0);
  }
  for (int i = 0; i < n - 1; i++) {
    int x, y;
    cin >> x >> y;
    paths[x - 1]++;
    paths[y - 1]++;
  }
  cout << *max_element(paths.begin(), paths.end()) + 1 << endl;
  return 0;
}
