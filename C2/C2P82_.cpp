#include <iostream>
#include <map>

using namespace std;

map<int, long> memo;

long scam(int, int, int[]);

int main() {
  int n;
  cin >> n;
  int price[n];
  for (int i = 0; i < n; i++) {
    cin >> price[i];
  }
  int k;
  cin >> k;
  cout << scam(k, n, price) << endl;
  return 0;
}

long scam(int k, int n, int price[]) {
  if (k < 0) return -1;
  if (k == 0) return 0;
  if (memo.count(k)) return memo[k];
  long res = 0;
  for (int i = 0; i < n; i++) {
    long pr = scam(k - i - 1, n, price);
    if (pr >= 0) {
      pr += price[i];
      if (pr > res) res = pr;
    }
  }
  memo[k] = res;
  return res;
}
