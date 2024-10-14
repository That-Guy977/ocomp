#include <stdio.h>

int main() {
  double w, h;
  scanf("%lf %lf", &w, &h);
  printf("%.2f\n", w);
  printf("%.2f\n", h);
  printf("%.2f\n", w / h / h);
  return 0;
}
