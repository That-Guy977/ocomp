#include <stdio.h>
#include <math.h>
#define EPSILON 1e-6

int main() {
  int n;
  scanf("%d", &n);
  double a[n][n];
  double b[n];
  double inv[n][n];
  for (int i = 0; i < n; i++) {
    for (int j = 0; j < n; j++) {
      scanf("%lf", &a[i][j]);
    }
  }
  for (int i = 0; i < n; i++) {
    scanf("%lf", &b[i]);
  }
  for (int i = 0; i < n; i++) {
    for (int j = 0; j < n; j++) {
      inv[i][j] = i == j;
    }
  }
  for (int i = 0; i < n; i++) {
    int rt = -1;
    for (int j = i; j < n; j++) {
      if (fabs(a[j][i]) > EPSILON) {
        rt = j;
        break;
      }
    }
    if (rt == -1) {
      printf("HMMM\n");
      return 0;
    }
    if (rt != i) {
      double temp;
      for (int j = i; j < n; j++) {
        temp = a[i][j];
        a[i][j] = a[rt][j];
        a[rt][j] = temp;
        temp = inv[i][j];
        inv[i][j] = inv[rt][j];
        inv[rt][j] = temp;
      }
      temp = b[i];
      b[i] = b[rt];
      b[rt] = temp;
    }
    double pivot = a[i][i];
    for (int j = 0; j < n; j++) {
      a[i][j] /= pivot;
      inv[i][j] /= pivot;
    }
    b[i] /= pivot;
    for (int j = i + 1; j < n; j++) {
      double f = a[j][i];
      for (int k = 0; k < n; k++) {
        a[j][k] -= f * a[i][k];
        inv[j][k] -= f * inv[i][k];
      }
      b[j] -= f * b[i];
    }
  }
  for (int i = n - 1; i > 0; i--) {
    for (int j = 0; j < i; j++) {
      double f = a[j][i];
      a[j][i] -= f * a[i][i];
      for (int k = 0; k < n; k++) {
        inv[j][k] -= f * inv[i][k];
      }
      b[j] -= f * b[i];
    }
  }
  for (int i = 0; i < n; i++) {
    for (int j = 0; j < n; j++) {
      if (j) printf(" ");
      printf("%f", inv[i][j]);
    }
    printf("\n");
  }
  for (int i = 0; i < n; i++) {
    printf("X%d = %f\n", i + 1, b[i]);
  }
  return 0;
}
