#include <stdio.h>

int main() {
  int a, b, c, n;
  scanf("%d %d %d %d", &a, &b, &c, &n);
  int first = 1;
  for (int i = 0; i <= n / a; i++) {
    for (int j = 0; j <= (n - a * i) / b; j++) {
      if ((n - a * i - b * j) % c == 0) {
        int k = (n - a * i - b * j) / c;
        if (!first) printf("\n");
        printf("Use %d %s of type A : %d\n", i, i <= 1 ? "coin" : "coins", i * a);
        printf("Use %d %s of type B : %d\n", j, j <= 1 ? "coin" : "coins", j * b);
        printf("Use %d %s of type C : %d\n", k, k <= 1 ? "coin" : "coins", k * c);
        first = 0;
      }
    }
  }
  if (first) printf("-1\n");
  return 0;
}
