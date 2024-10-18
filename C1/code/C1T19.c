#include <stdio.h>
#define MIN(a, b) (a < b ? a : b)

int solve(int n) {
  static int memo[50] = { -1 };
  if (memo[0] == -1) {
    for (int i = 0; i < 50; i++) {
      memo[i] = -1;
    }
  }
  if (n == 1) return 0;
  if (memo[n] != -1) return memo[n];
  int mn = 0;
  for (int i = 1; i <= n / 2; i++) {
    if (n % i == 0) {
      int res = solve(n - i) + 1;
      if (!mn || res < mn) mn = res;
    }
  }
  memo[n] = mn;
  return mn;
}

int main() {
  int n;
  scanf("%d", &n);
  printf("%d\n", solve(n));
  return 0;
}
