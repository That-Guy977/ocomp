#include <stdio.h>
#define MAX(a, b) (a > b ? a : b)
#define MIN(a, b) (a < b ? a : b)

int main() {
  int n;
  scanf("%d", &n);
  int a[n];
  for (int i = 0; i < n; i++) {
    scanf("%d", &a[i]);
  }
  int b[n];
  for (int i = 0; i < n; i++) {
    scanf("%d", &b[i]);
  }
  int ap = 0;
  int bp = 0;
  for (int i = 0; i < n; i++) {
    if (a[i] > b[i]) {
      ap += 2;
    } else if (a[i] < b[i]) {
      bp += 2;
    } else {
      ap++;
      bp++;
    }
  }
  if (ap > bp) {
    printf("1\n");
  } else if (ap < bp) {
    printf("2\n");
  } else {
    printf("D\n");
  }
  printf("%d %d\n", MAX(ap, bp), MIN(ap, bp));
  return 0;
}
