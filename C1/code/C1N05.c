#include <stdio.h>

int main() {
  int n;
  scanf("%d", &n);
  printf("%d\n", n / 60 / 24);
  n %= 60 * 24;
  printf("%d\n", n / 60);
  n %= 60;
  printf("%d\n", n);
  return 0;
}
