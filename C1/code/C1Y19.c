#include <stdio.h>

long exponential(int b, int e) {
  if (e == 0) return 1;
  return b * exponential(b, e - 1);
}

int main() {
  int b, e;
  scanf("%d %d", &b, &e);
  printf("%ld\n", exponential(b, e));
  return 0;
}
