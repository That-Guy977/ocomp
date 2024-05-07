#include <iostream>
#include <vector>
#include <cmath>

using namespace std;

int main() {
  int n;
  cin >> n;
  vector<int> h;
  int count = 0;
  for (int i = 0; i < n; i++) {
    int hi;
    cin >> hi;
    h.push_back(hi);
    count += h[i];
  }
  int tlen = count / n;
  int moves = 0;
  for (int& len : h) {
    moves += abs(tlen - len);
  }
  cout << moves / 2 << endl;
  return 0;
}
