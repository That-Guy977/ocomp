#include <stdio.h>

int main() {
  int n;
  scanf("%d", &n);
  printf("2");
  for (int i = 3; i <= n; i += 2) {
    int digitsum = 0;
    int p = i;
    while (p) {
      digitsum += p % 10;
      p /= 10;
    }
    if (digitsum != 2 && digitsum % 2 == 0) continue;
    int prime = 1;
    for (int k = 3; k < i; k += 2) {
      if (i % k == 0 || k < digitsum && digitsum % k == 0) {
        prime = 0;
        break;
      }
    }
    if (prime) {
      printf(" %d", i);
    }
  }
  printf("\n");
  return 0;
}
