#include <stdio.h>

int prime(int n) {
  if (n < 2) return 0;
  if (n == 2) return 1;
  if (n % 2 == 0) return 0;
  for (int i = 3; i < n / 2; i += 2) {
    if (n % i == 0) return 0;
  }
  return 1;
}

int main() {
  int n;
  scanf("%d", &n);
  int s = 0;
  int e = 0;
  for (int i = 0; i < n; i++) {
    int x;
    scanf("%d", &x);
    if (!s || x < s) s = x;
    if (!e || x > e) e = x;
  }
  int first = 1;
  for (int i = s; i <= e; i++) {
    if (prime(i)) {
      if (!first) printf(" ");
      printf("%d", i);
      first = 0;
    }
  }
  printf("\n");
  return 0;
}
