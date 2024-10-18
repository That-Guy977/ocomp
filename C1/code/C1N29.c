#include <stdio.h>
#include <math.h>

int main() {
  long n;
  scanf("%ld", &n);
  long sum = 0;
  if (n < 1 || n > 10) return 0;
  for (int i = 1; i <= n; i++) {
    sum += pow(i, i);
  }
  printf("%ld\n", sum);
  return 0;
}
