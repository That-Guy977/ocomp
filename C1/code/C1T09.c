#include <stdio.h>

int main() {
  int n;
  scanf("%d", &n);
  for (int i = 0; i < 2 * n + 3; i++) {
    if (i) printf(" ");
    printf("*");
  }
  printf("\n");
  for (int i = 0; i < n; i++) {
    printf("* ");
    for (int j = 0; j < i + 1; j++) printf(". ");
    for (int j = 0; j < n - i - 1; j++) printf("  ");
    if (i % 2 == 0) printf("%c ", i / 2 % 26 + 'A');
    else printf("%c ", i / 2 % 9 + '1');
    for (int j = 0; j < n - i - 1; j++) printf("  ");
    for (int j = 0; j < i + 1; j++) printf(". ");
    printf("*\n");
  }
  for (int i = 0; i < 2 * n + 3; i++) {
    if (i) printf(" ");
    printf("*");
  }
  printf("\n");
  return 0;
}
