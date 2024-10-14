#include <stdio.h>

int main() {
  int m, n, p, q;
  scanf("%d %d %d %d", &m, &n, &p, &q);
  int a[m][n];
  int b[p][q];
  for (int i = 0; i < m; i++) {
    for (int j = 0; j < n; j++) {
      scanf("%d", &a[i][j]);
    }
  }
  for (int i = 0; i < p; i++) {
    for (int j = 0; j < q; j++) {
      scanf("%d", &b[i][j]);
    }
  }
  if (n == p) {
    int r[m][q];
    for (int i = 0; i < m; i++) {
      for (int j = 0; j < q; j++) {
        r[i][j] = 0;
        for (int k = 0; k < n; k++) {
          r[i][j] += a[i][k] * b[k][j];
        }
      }
    }
    for (int i = 0; i < m; i++) {
      for (int j = 0; j < q; j++) {
        if (j) printf(" ");
        printf("%d", r[i][j]);
      }
      printf("\n");
    }
  } else {
    printf("No Solution\n");
  }
  return 0;
}
