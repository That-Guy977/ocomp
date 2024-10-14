#include <stdio.h>

int main() {
  char type;
  int n;
  scanf("%c %d", &type, &n);
  switch (type) {
    case 'A':
      printf("%.2f\n", 1000000 * n * 0.05);
      break;
    case 'B':
      printf("%.2f\n", 1500000 * n * 0.07);
      break;
    case 'C':
      printf("%.2f\n", 2500000 * n * 0.10);
      break;
    default:
      printf("Invalid\n");
      break;
  }
  return 0;
}
