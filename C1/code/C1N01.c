#include <stdio.h>

int main() {
  int total = 0;
  for (int i = 0; i < 5; i++) {
    int x;
    scanf("%d", &x);
    total += x;
  }
  printf("%d\n", total);
  printf("%.2f\n", (double) total / 5);
  return 0;
}
