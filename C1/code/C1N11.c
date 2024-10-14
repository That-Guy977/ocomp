#include <stdio.h>

int main() {
  int mx = 0;
  int mn = 0;
  int total = 0;
  for (int i = 0; i < 10; i++) {
    int x;
    scanf("%d", &x);
    if (!mx || x > mx) mx = x;
    if (!mn || x < mn) mn = x;
    total += x;
  }
  printf("%d\n", mn);
  printf("%d\n", mx);
  printf("%.2f\n", (double) total / 10);
  return 0;
}
