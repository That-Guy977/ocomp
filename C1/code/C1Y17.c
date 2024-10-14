#include <stdio.h>

int main() {
  int x;
  scanf("%d", &x);
  if (x >= 0) {
    int n = 1;
    while (x >> n) {
      n++;
    }
    for (int i = n - 1; i >= 0; i--) {
      printf("%d", x >> i & 1);
    }
    printf("\n");
  } else {
    printf("error\n");
  }
  return 0;
}
