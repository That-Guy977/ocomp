#include <stdio.h>
#define MAX(a, b) (a > b ? a : b)
#define MIN(a, b) (a < b ? a : b)

int main() {
  int n, l;
  scanf("%d %d", &n, &l);
  int dmg = 0;
  for (int i = 0; i < n; i++) {
    int p, r, d;
    scanf("%d %d %d", &p, &r, &d);
    dmg += d * (MIN(p + r, l - 1) - MAX(p - r, 0) + 1);
  }
  int q;
  scanf("%d", &q);
  for (int i = 0; i < q; i++) {
    int hp;
    scanf("%d", &hp);
    if (hp <= dmg) {
      printf("Cleared\n");
    } else {
      printf("Destroyed\n");
    }
  }
  return 0;
}
