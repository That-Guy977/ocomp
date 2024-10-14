#include <stdio.h>

int gcd(int a, int b) {
  if (b == 0) return a;
  return gcd(b, a % b);
}

int main() {
  int a, b;
  scanf("%d %d", &a, &b);
  int d = gcd(a, b);
  printf("%d %d\n", d, a * b / d);
  return 0;
}
