#include <stdio.h>
#include <ctype.h>

int main() {
  char tier;
  double b;
  scanf("%c %lf", &tier, &b);
  tier = tolower(tier);
  switch (tier) {
    case 'w':
      printf("%.2f\n", b * 0.20);
      break;
    case 'g':
      printf("%.2f\n", b * 0.25);
      break;
    case 'p':
      printf("%.2f\n", b * 0.30);
      break;
    default:
      printf("Data not found...\n");
      break;
  }
  return 0;
}
