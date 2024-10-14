#include <stdio.h>

int main() {
  int n, m;
  scanf("%d %d", &n, &m);
  if (n < -100 || n > 100 || m < -100 || m > 100) {
    printf("Error\n");
    return 0;
  }
  printf("%d %d\n", m, n);
  return 0;
}
