#include <stdio.h>

int main() {
  int x, y;
  scanf("%d %d", &x, &y);
  if (x <= y) {
    for (int i = x; i <= y; i++) {
      if (i != x) printf(" ");
      printf("%d", i);
    }
    printf("\n");
  } else {
    printf("Invalid\n");
  }
  return 0;
}
