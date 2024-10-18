#include <stdio.h>
#define MAX(a, b) (a > b ? a : b)

int solve(int, int, int, int[*], int[*]);

int main() {
  int n, k;
  scanf("%d %d", &n, &k);
  int x[n];
  int y[n];
  for (int i = 0; i < n; i++) {
    scanf("%d %d", &x[i], &y[i]);
  }
  printf("%d\n", solve(0, k, n, x, y));
  return 0;
}

int solve(int i, int k, int n, int x[n], int y[n]) {
  if (i == n) return 0;
  if (y[i] > k) return solve(i + 1, k, n, x, y);
  return MAX(solve(i + 1, k - y[i], n, x, y) + x[i], solve(i + 1, k, n, x, y));
}
