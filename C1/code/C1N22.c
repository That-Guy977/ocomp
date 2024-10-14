#include <stdio.h>
#define MIN(a, b) (a < b ? a : b)

int main() {
  int ha, ma, hb, mb;
  scanf("%d %d %d %d", &ha, &ma, &hb, &mb);
  int t = (hb * 60 + mb) - (ha * 60 + ma);
  int cost = 0;
  if (t > 15) cost += MIN(30, (t + 59) / 60 * 10);
  if (t > 3 * 60) cost += MIN(60, (t - 3 * 60 + 59) / 60 * 20);
  if (t > 6 * 60) cost = 200;
  printf("%d\n", cost);
  return 0;
}
