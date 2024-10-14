#include <stdio.h>

int main() {
  int even = 0;
  int odd = 0;
  for (int i = 0; i < 8; i++) {
    int x;
    scanf("%d", &x);
    if (x % 2 == 0) {
      even += x;
    } else {
      odd += x;
    }
  }
  if (even > odd) {
    printf("even\n");
  } else if (even < odd) {
    printf("odd\n");
  } else {
    printf("equal\n");
  }
  printf("%d\n", even);
  printf("%d\n", odd);
  return 0;
}
