#include <stdio.h>

int main() {
  int n;
  scanf("%d", &n);
  for (int i = 1; i <= (n + 1) / 2; i++) {
    for (int j = 1; j < i; j++) printf("%d", j % 10);
    for (int j = 1; j <= n; j++) printf("%d", i % 10);
    for (int j = 1; j <= n - (i - 1) * 2; j++) printf(" ");
    for (int j = 1; j <= n; j++) printf("%d", i % 10);
    for (int j = i - 1; j > 0; j--) printf("%d", j % 10);
    printf("\n");
  }
  for (int i = 1; i <= n / 2; i++) {
    for (int j = 1; j <= n / 2 + i; j++) printf("%d", j % 10);
    for (int j = 1; j <= n + (n - 1) / 2 * 2 - (i - 1) * 2; j++) printf("%d", ((n + 1) / 2 + i) % 10);
    for (int j = n / 2 + i; j > 0; j--) printf("%d", j % 10);
    printf("\n");
  }
  for (int i = 1; i <= (n + 1) / 2; i++) {
    for (int j = 1; j <= i; j++) printf(" ");
    for (int j = 1; j < n; j++) printf("%d", (i + j) % 10);
    for (int j = 1; j <= n - (i - 1) * 2; j++) printf("%d", (n + i) % 10);
    for (int j = n - 1; j > 0; j--) printf("%d", (i + j) % 10);
    printf("\n");
  }
  for (int i = n / 2; i > 0; i--) {
    for (int j = 1; j <= i; j++) printf(" ");
    for (int j = 1; j < n; j++) printf("%d", (i + j) % 10);
    for (int j = 1; j <= n - (i - 1) * 2; j++) printf("%d", (n + i) % 10);
    for (int j = n - 1; j > 0; j--) printf("%d", (i + j) % 10);
    printf("\n");
  }
  for (int i = n / 2; i > 0; i--) {
    for (int j = 1; j <= n / 2 + i; j++) printf("%d", j % 10);
    for (int j = 1; j <= n + (n - 1) / 2 * 2 - (i - 1) * 2; j++) printf("%d", ((n + 1) / 2 + i) % 10);
    for (int j = n / 2 + i; j > 0; j--) printf("%d", j % 10);
    printf("\n");
  }
  for (int i = (n + 1) / 2; i > 0; i--) {
    for (int j = 1; j < i; j++) printf("%d", j % 10);
    for (int j = 1; j <= n; j++) printf("%d", i % 10);
    for (int j = 1; j <= n - (i - 1) * 2; j++) printf(" ");
    for (int j = 1; j <= n; j++) printf("%d", i % 10);
    for (int j = i - 1; j > 0; j--) printf("%d", j % 10);
    printf("\n");
  }
  return 0;
}
