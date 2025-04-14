#include <iostream>
#include <algorithm>
#include <map>
#include <tuple>

using namespace std;

int solve(int, int, int[], int, int, int);

int main() {
  int n, m, k;
  cin >> n >> m >> k;
  int l[n * m];
  for (int i = 0; i < n * m; i++) {
    cin >> l[i];
  }
  int mx = 0;
  for (int i = 0; i < n; i++) {
    int res = solve(n, m, l, -1, i, k);
    if (res > mx) mx = res;
  }
  cout << mx << endl;
  return 0;
}

int solve(int n, int m, int l[], int i, int j, int k) {
  static map<tuple<int, int, int>, int> memo;
  if (memo.count({ i, j, k })) return memo[{ i, j, k }];
  int ip = i + 1;
  if (ip >= m) return 0;
  int res = max({
    solve(n, m, l, ip, j, k) + l[j * m + ip],
    j < n - 1 && k < m - ip ? solve(n, m, l, ip, j + 1, k) + l[(j + 1) * m + ip] : 0,
    j > 0     && k < m - ip ? solve(n, m, l, ip, j - 1, k) + l[(j - 1) * m + ip] : 0,
    j < n - 1 && k ? solve(n, m, l, ip, j + 1, k - 1) + l[j * m + ip] + l[(j + 1) * m + ip] : 0,
    j > 0     && k ? solve(n, m, l, ip, j - 1, k - 1) + l[j * m + ip] + l[(j - 1) * m + ip] : 0
  });
  memo[{ i, j, k }] = res;
  return res;
}
