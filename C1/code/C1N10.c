#include <stdio.h>

int main() {
  int odd = 0;
  int even = 0;
  int mxodd = 0;
  int mxeven = 0;
  for (int i = 0; i < 10; i++) {
    int x;
    scanf("%d", &x);
    if (x % 2 == 1) {
      odd++;
      if (x > mxodd) mxodd = x;
    } else {
      even++;
      if (x > mxeven) mxeven = x;
    }
  }
  printf("%d\n", odd);
  printf("%d\n", even);
  printf("%d\n", mxodd);
  printf("%d\n", mxeven);
  return 0;
}
