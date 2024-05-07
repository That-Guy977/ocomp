#include <iostream>
#include <vector>
#include <map>
#include <set>
#include <tuple>

using namespace std;

map<pair<int, int>, long> memo;

long p(int, int, int);

int main() {
  int n, f, sum;
  cin >> n >> f >> sum;
  cout << p(n, f, sum) << endl;
  return 0;
}

long p(int n, int f, int sum) {
  if (memo.count({ n, sum })) return memo[{ n, sum }];
  if (n * f < sum || n > sum) return 0;
  if (n == 0) return 1;
  long res = 0;
  for (int i = 1; i <= f; i++) {
    res += p(n - 1, f, sum - i);
  }
  memo[{ n, sum }] = res;
  return res;
}
