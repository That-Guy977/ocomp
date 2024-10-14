#include <stdio.h>

int main() {
  float a, b;
  scanf("%f %f", &a, &b);
  if (b > 0) {
    printf("%.1f\n", a + b);
  } else {
    printf("%.1f\n", a * b);
  }
  return 0;
}
