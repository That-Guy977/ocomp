#include <stdio.h>

int main() {
  int n;
  scanf("%d", &n);
  char a, b, c, d;
  scanf(" %c %c %c %c", &a, &b, &c, &d);
  for (int i = 0; i < n; i++) {
    for (int j = 0; j < n - i; j++) printf("%c ", a);
    for (int j = 0; j < i; j++) printf("%c ", c);
    for (int j = 0; j < i; j++) printf(" %c", d);
    for (int j = 0; j < n - i; j++) printf(" %c", b);
    printf("\n");
  }
  printf("\n");
  for (int i = n - 1; i >= 0; i--) {
    for (int j = 0; j < n - i; j++) printf("%c ", b);
    for (int j = 0; j < i; j++) printf("%c ", d);
    for (int j = 0; j < i; j++) printf(" %c", c);
    for (int j = 0; j < n - i; j++) printf(" %c", a);
    printf("\n");
  }
  return 0;
}
