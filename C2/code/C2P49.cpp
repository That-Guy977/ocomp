#include <iostream>
#include <algorithm>
#include <map>

using namespace std;

map<int, int> memo;

int grab(int, int[], int);

int main() {
  int n;
  cin >> n;
  int stones[n];
  for (int i = 0; i < n; i++) {
    cin >> stones[i];
  }
  cout << grab(n, stones, -2) << endl;
  return 0;
}

int grab(int n, int stones[], int prev) {
  if (prev >= n) return 0;
  if (memo.count(prev)) return memo[prev];
  int res = (prev >= 0 ? stones[prev] : 0) + max(
    grab(n, stones, prev + 2),
    grab(n, stones, prev + 3)
  );
  memo[prev] = res;
  return res;
}
