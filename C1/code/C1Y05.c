#include <stdio.h>

int main() {
  int n;
  scanf("%d", &n);
  if (n >= 1000) printf("100\n");
  else if (n >= 0) printf("0\n");
  else printf("Error\n");
  return 0;
}
