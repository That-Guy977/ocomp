#include <stdio.h>

int main() {
  int n, k, s;
  scanf("%d %d %d", &n, &k, &s);
  int first = 1;
  int box[k];
  for (int i = 0; i < k; i++) {
    box[i] = 0;
  }
  int sum = 0;
  do {
    if (sum + k != s) {
      if (!first) printf(" ");
      printf("(");
      for (int i = 0; i < k; i++) {
        if (i) printf(", ");
        printf("%d", box[i] + 1);
      }
      printf(")");
      first = 0;
    }
    int p = k - 1;
    box[p]++;
    sum++;
    while (box[p] == n) {
      box[p] = 0;
      sum -= n;
      if (--p < 0) break;
      box[p]++;
      sum++;
    }
  } while (sum != 0);
  printf("\n");
  return 0;
}
