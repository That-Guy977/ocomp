#include <stdio.h>

int main() {
  long x[3];
  for (int i = 0; i < 3; i++) {
    scanf("%ld", &x[i]);
  }
  for (int i = 0; i < 2; i++) {
    for (int j = 0; j < 2; j++) {
      if (x[j] < x[j + 1]) {
        long temp = x[j];
        x[j] = x[j + 1];
        x[j + 1] = temp;
      }
    }
  }
  for (int i = 0; i < 3; i++) {
    if (i) printf(" ");
    printf("%ld", x[i]);
  }
  printf("\n");
  return 0;
}
