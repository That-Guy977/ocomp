#include <iostream>
#include <algorithm>
#include <map>
#include <tuple>

using namespace std;

typedef map<pair<int, int>, long> projectlist;

long accept(int, projectlist::iterator, projectlist::iterator);

int main() {
  int n;
  cin >> n;
  projectlist proj;
  int e = 0;
  for (int i = 0; i < n; i++) {
    int a, b, r;
    cin >> a >> b >> r;
    if (r > proj[{ a, b }]) {
      proj[{ a, b }] = r;
    }
  }
  cout << accept(0, proj.begin(), proj.end()) << endl;
  return 0;
}

long accept(int day, projectlist::iterator it, projectlist::iterator end) {
  static map<int, long> memo;
  while (it != end && it->first.first <= day) ++it;
  if (it == end) return 0;
  auto [d, r] = *it;
  auto [a, b] = d;
  ++it;
  if (memo.count(a)) return memo[a];
  long res = max(
    accept(day, it, end),
    accept(b, it, end) + r
  );
  memo[a] = res;
  return res;
}
