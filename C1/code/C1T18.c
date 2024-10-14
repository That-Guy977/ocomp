#include <stdio.h>
#include <stdlib.h>

int main() {
  int n = 0;
  int x[1000000];
  while (scanf("%d-", &x[n++]) == 1);
  n--;
  int f[1000000];
  for (int i = 0; i < 1000000; i++) {
    f[i] = 0;
  }
  long total = 0;
  for (int i = 0; i < n; i++) {
    total += x[i];
    f[x[i]]++;
  }
  int avg = (double) total / n;
  int mx = 0;
  int mod = 0;
  for (int i = 0; i < 1000000; i++) {
    if (f[i] > mx) {
      mx = f[i];
      mod = i;
    } else if (f[i] == mx && abs(i - avg) < abs(mod - avg)) {
      mod = i;
    }
  }
  printf("%d %d\n", mod, mx);
  return 0;
}
