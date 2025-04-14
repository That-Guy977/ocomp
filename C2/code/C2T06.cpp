#include <iostream>
#define MOD 1000000007

using namespace std;

int main() {
  int n, k;
  cin >> n >> k;
  long state[k];
  long next = 0;
  for (int i = 0; i < n; i++) {
    if (i < k) {
      state[i] = next + 1;
      next += state[i];
    } else {
      long prev = state[i % k];
      state[i % k] = next;
      next -= prev;
      next += state[i % k];
    }
    state[i % k] %= MOD;
    next %= MOD;
  }
  long res = state[(n - 1) % k];
  while (res < 0) res += MOD;
  cout << res << endl;
  return 0;
}
