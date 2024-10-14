#include <stdio.h>

int main() {
  int n;
  scanf("%d", &n);
  for (int i = 1; i < n; i++) {
    for (int j = 1; j < i; j++) printf(" ");
    printf("%d", i);
    for (int j = 1; j < n * 2 - i * 2; j++) printf(" ");
    printf("%d", i);
    printf("\n");
  }
  for (int i = 1; i < n; i++) printf(" ");
  printf("%d\n", n);
  for (int i = n - 1; i > 0; i--) {
    for (int j = 1; j < i; j++) printf(" ");
    printf("%d", i);
    for (int j = 1; j < n * 2 - i * 2; j++) printf(" ");
    printf("%d", i);
    printf("\n");
  }
  return 0;
}
