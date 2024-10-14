#include <stdio.h>

int main() {
  int n;
  scanf("%d", &n);
  if (n < 3 || n > 100) {
    printf("Invalid");
    return 0;
  }
  int x[n];
  for (int i = 0; i < n; i++) {
    scanf("%d", &x[i]);
  }
  for (int i = 0; i < n - 1; i++) {
    int mnidx = i;
    for (int j = i + 1; j < n; j++) {
      if (x[j] < x[mnidx]) mnidx = j;
    }
    int temp = x[i];
    x[i] = x[mnidx];
    x[mnidx] = temp;
  }
  printf("%d\n", x[0]);
  printf("%d\n", x[n - 1]);
  if (n % 2 == 1) {
    printf("%d\n", x[n / 2]);
  } else {
    printf("%.2f\n", (double) (x[n / 2 + 1] + x[n / 2]) / 2);
  }
  return 0;
}
