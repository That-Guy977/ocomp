#include <stdio.h>

int main() {
  int n;
  scanf("%d", &n);
  int x[n];
  for (int i = 0; i < n; i++) {
    scanf("%d", &x[i]);
  }
  int k;
  scanf("%d", &k);
  int found = 0;
  for (int i = 0; i < n; i++) {
    if (x[i] == k) {
      if (found) printf(" ");
      printf("%d", i + 1);
      found = 1;
    }
  }
  if (!found) printf("0");
  printf("\n");
  return 0;
}
