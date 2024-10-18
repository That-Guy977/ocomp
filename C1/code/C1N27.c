#include <stdio.h>
#define MAX(a, b) (a > b ? a : b)

int main() {
  int n;
  scanf("%d", &n);
  int total = 0;
  for (int i = 0; i < n; i++) {
    int w, l, h;
    scanf("%d %d %d", &w, &l, &h);
    total += MAX(MAX(w, l), h);
  }
  printf("%d\n", total);
  return 0;
}
