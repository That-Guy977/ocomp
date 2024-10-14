#include <stdio.h>

int main() {
  int n;
  scanf("%d", &n);
  for (int i = 0; i < n - 1; i++) {
    for (int j = 0; j < i; j++) printf(" ");
    printf("%d", ((n - i - 2) * 4 + 1) % 10);
    for (int j = 0; j < (n - 2) * 2 - i * 2 + 1; j++) printf(" ");
    printf("%d", ((n - i - 2) * 4 + 4) % 10);
    printf("\n");
  }
  for (int i = 0; i < n - 1; i++) printf(" ");
  printf("%c\n", n % 26 + 'A' - 1);
  for (int i = n - 2; i >= 0; i--) {
    for (int j = 0; j < i; j++) printf(" ");
    printf("%d", ((n - i - 2) * 4 + 3) % 10);
    for (int j = 0; j < (n - 2) * 2 - i * 2 + 1; j++) printf(" ");
    printf("%d", ((n - i - 2) * 4 + 2) % 10);
    printf("\n");
  }
  return 0;
}
