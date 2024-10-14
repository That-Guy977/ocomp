#include <stdio.h>

int main() {
  int n;
  scanf("%d", &n);
  int x[n];
  for (int i = 0; i < n; i++) {
    scanf("%d", &x[i]);
  }
  for (int i = 0; i < n - 1; i++) {
    for (int j = 0; j < n - 1; j++) {
      if (x[j] > x[j + 1]) {
        int temp = x[j];
        x[j] = x[j + 1];
        x[j + 1] = temp;
      }
    }
  }
  int uniq = 0;
  int u[n];
  for (int i = 0; i < n; i++) {
    if (!uniq || x[i] != u[uniq - 1]) {
      u[uniq++] = x[i];
    }
  }
  printf("%d\n", uniq);
  for (int i = 0; i < uniq; i++) {
    if (i) printf(" ");
    printf("%d", u[i]);
  }
  printf("\n");
  return 0;
}
