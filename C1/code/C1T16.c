#include <stdio.h>

int main() {
  int n, m;
  scanf("%d %d", &n, &m);
  for (int i = 0; i < n; i++) {
    int k = i % ((m - 1) * 2);
    if (k < m / 2) {
      for (int i = 0; i < k % (m - 1); i++) printf(" ");
      printf("%c", i % 26 + 'A');
      for (int i = 0; i < m - (k % (m - 1) + 1) * 2; i++) printf(" ");
      printf("%c", i % 10 + '0');
    } else if (m % 2 && k == m / 2) {
      for (int i = 0; i < m / 2; i++) printf(" ");
      printf("%c", i % 26 + 'A');
    } else if (k < m - 1) {
      for (int i = 0; i < m - k % (m - 1) - 1; i++) printf(" ");
      printf("%c", i % 10 + '0');
      for (int i = 0; i < m - (m - k % (m - 1)) * 2; i++) printf(" ");
      printf("%c", i % 26 + 'A');
    } else if (k < m + m / 2 - 1) {
      for (int i = 0; i < k % (m - 1); i++) printf(" ");
      printf("%c", i % 10 + '0');
      for (int i = 0; i < m - (k % (m - 1) + 1) * 2; i++) printf(" ");
      printf("%c", i % 26 + 'A');
    } else if (m % 2 && k == m + m / 2 - 1) {
      for (int i = 0; i < m / 2; i++) printf(" ");
      printf("%c", i % 26 + 'A');
    } else {
      for (int i = 0; i < m - k % (m - 1) - 1; i++) printf(" ");
      printf("%c", i % 26 + 'A');
      for (int i = 0; i < m - (m - k % (m - 1)) * 2; i++) printf(" ");
      printf("%c", i % 10 + '0');
    }
    printf("\n");
  }
  return 0;
}
