#include <stdio.h>

int main() {
  int n;
  scanf("%d", &n);
  int b = 1;
  while (n >> b) {
    b++;
  }
  for (int i = b - 1; i >= 0; i--) {
    printf("%d", n >> i & 1);
  }
  printf("\n");
  return 0;
}
