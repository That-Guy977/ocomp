#include <stdio.h>

int main() {
  int n;
  scanf("%d", &n);
  if (80 <= n && n <= 100) printf("A\n");
  else if (70 <= n && n < 80) printf("B\n");
  else if (60 <= n && n < 70) printf("C\n");
  else if (50 <= n && n < 60) printf("D\n");
  else if (0 <= n && n < 50) printf("F\n");
  else printf("Error\n");
  return 0;
}
