#include <stdio.h>

int main() {
  int mx = 0;
  int mn = 0;
  for (int i = 0; i < 10; i++) {
    int x;
    scanf("%d", &x);
    if (x > 0) {
      if (!mx || x > mx) mx = x;
      if (!mn || x < mn) mn = x;
    }
  }
  printf("%d %d\n", mx, mn);
  return 0;
}
