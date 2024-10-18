#include <stdio.h>

long solve(int n) {
  if (n < 0) return 0;
  if (n <= 1) return 1;
  return solve(n - 1) * 2 - solve(n - 7);
}

int main() {
  int n;
  scanf("%d", &n);
  printf("%ld\n", solve(n));
  return 0;
}
