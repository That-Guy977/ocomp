#include <stdio.h>

int main() {
  int n;
  scanf("%d", &n);
  if (n <= 0 || n > 100) {
    printf("Error\n");
    return 0;
  }
  int x[n];
  for (int i = 0; i < n; i++) {
    scanf("%d", &x[i]);
    if (x[i] < -100 || x[i] > 100) {
      printf("Error\n");
      return 0;
    }
  }
  int k;
  scanf("%d", &k);
  for (int i = 0; i < n; i++) {
    if (x[i] == k) {
      printf("%d\n", i);
      break;
    }
  }
  return 0;
}
