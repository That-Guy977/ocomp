#include <stdio.h>
#define MAX(a, b) (a > b ? a : b)

int main() {
  int n;
  scanf("%d", &n);
  int first = 1;
  int pprev, prev;
  scanf("%d", &pprev);
  if (n == 1) {
    printf("%d\n", pprev);
    return 0;
  }
  scanf("%d", &prev);
  if (pprev >= prev) {
    printf("%d", pprev);
    first = 0;
  }
  for (int i = 2; i < n; i++) {
    int x;
    scanf("%d", &x);
    if (prev >= pprev && prev >= x) {
      if (!first) printf(" ");
      printf("%d", prev);
      first = 0;
    }
    pprev = prev;
    prev = x;
  }
  if (prev >= pprev) {
    if (!first) printf(" ");
    printf("%d", prev);
  }
  printf("\n");
  return 0;
}
