#include <stdio.h>

int main() {
  int a, b;
  scanf("%d %d", &a, &b);
  printf("%.2f\n", (double) (a * b) / 2);
  printf("%d\n", a * b);
  return 0;
}
