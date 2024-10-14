#include <stdio.h>

int main() {
  int n = 0;
  double sum = 0;
  double x;
  while (1) {
    scanf("%lf", &x);
    if (!x) break;
    sum += x;
    n++;
  }
  if (n) {
    printf("%.6f\n", sum / n);
  } else {
    printf("No data\n");
  }
  return 0;
}
