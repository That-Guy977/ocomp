#include <stdio.h>

int main() {
  int x;
  scanf("%d", &x);
  if (x) {
    int mx = x;
    int mn = x;
    while (1) {
      scanf("%d", &x);
      if (!x) break;
      if (x > mx) mx = x;
      if (x < mn) mn = x;
    }
    printf("%d %d\n", mx, mn);
  } else {
    printf("No data\n");
  }
  return 0;
}
