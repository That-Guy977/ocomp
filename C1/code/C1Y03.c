#include <stdio.h>

int main() {
  int a, b, c, d, e, f;
  scanf("%d %d %d %d %d %d", &a, &b, &c, &d, &e, &f);
  int x = a % 10 * 100 + b % 10 * 10 + c % 10;
  int y = d % 10 * 100 + e % 10 * 10 + f % 10;
  printf("%03d\n", (x + y) % 1000);
  return 0;
}
