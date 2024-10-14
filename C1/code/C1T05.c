#include <stdio.h>

int main() {
  int d, y, t, c;
  scanf("%d %d %d %d", &d, &y, &t, &c);
  double discount = 0;
  if (y % 4 == 0 && (y % 100 != 0 || y % 400 == 0)) {
    if (d > 7) discount += 0.10;
    else discount += 0.05;
    if (930 <= t && t <= 1130) discount += 0.30;
    else if (1130 < t && t <= 1330) discount += 0.20;
    else if (1330 < t && t <= 1830) discount += 0.15;
    else discount += 0.10;
  } else {
    if (d > 7) discount += 0.05;
    if (930 <= t && t <= 1130) discount += 0.15;
    else if (1130 < t && t <= 1330) discount += 0.10;
    else if (1330 < t && t <= 1830) discount += 0.05;
  }
  printf("%.2f", c * d * (1 - discount));
  return 0;
}
