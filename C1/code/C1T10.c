#include <stdio.h>

int main() {
  int n;
  scanf("%d", &n);
  int k = 0;
  for (int i = 0; i < n; i++) {
    if (i % 2 == 0) {
      for (int j = 0; j <= i; j++) {
        if (j) printf(" ");
        printf("%d", k++ % 10);
      }
    } else {
      k += i + 1;
      for (int j = 0; j <= i; j++) {
        if (j) printf(" ");
        printf("%d", (k - j - 1) % 10);
      }
    }
    printf("\n");
  }
  k--;
  for (int i = 0; i < n; i++) {
    for (int j = 0; j < i; j++) printf("  ");
    if (i % 2 == 0) {
      for (int j = 0; j < n - i; j++) {
        if (j) printf(" ");
        printf("%d", k-- % 10);
      }
    } else {
      k -= n - i;
      for (int j = 0; j < n - i; j++) {
        if (j) printf(" ");
        printf("%d", (k + j + 1) % 10);
      }
    }
    printf("\n");
  }
  return 0;
}
