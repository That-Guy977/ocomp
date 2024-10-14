#include <stdio.h>

int main() {
  int n;
  scanf("%d", &n);
  int mx = 0;
  int mn = 0;
  for (int i = 0; i < n; i++) {
    int x;
    scanf("%d", &x);
    if (!mx || x > mx) mx = x;
    if (!mn || x < mn) mn = x;
  }
  int r = mx - mn;
  int m, d;
  scanf("%d %d", &m, &d);
  for (int i = 0; i < m; i++) {
    int v;
    scanf("%d", &v);
    if (r - d <= v && v <= r + d) printf("/%d\\\n", v);
  }
  printf("%d %d\n", d, r);
  return 0;
}
