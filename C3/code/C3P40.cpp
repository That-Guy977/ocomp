#include <iostream>
#include <vector>
#include <map>
#include <array>

using namespace std;

const array<vector<int>, 10> moves {{
  { 8 },
  { 2, 4 },
  { 1, 3, 5 },
  { 2, 6 },
  { 1, 5, 7 },
  { 2, 4, 6, 8 },
  { 3, 5, 9 },
  { 4, 8 },
  { 5, 7, 9, 0 },
  { 6, 8 },
}};

long travel(int, int);

int main() {
  int n;
  cin >> n;
  long count = 0;
  for (int i = 0; i < 10; i++) {
    count += travel(n, i);
  }
  cout << count << endl;
  return 0;
}

long travel(int t, int d) {
  static array<map<int, long>, 10> memo;
  if (t == 1) return 1;
  if (memo[d].count(t)) return memo[d][t];
  long count = travel(t - 1, d);
  for (int next : moves[d]) {
    count += travel(t - 1, next);
  }
  memo[d][t] = count;
  return count;
}
