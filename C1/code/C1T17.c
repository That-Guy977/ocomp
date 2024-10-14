#include <stdio.h>
#define MIN(a, b) (a < b ? a : b)

int main() {
  int n;
  scanf("%d", &n);
  long x[n];
  for (int i = 0; i < n; i++) {
    scanf("%ld", &x[i]);
  }
  int mxl = 0;
  int mxr = 0;
  long mx = 0;
  for (int i = 0; i < n; i++) {
    for (int j = i + 1; j < n; j++) {
      long v = (j - i) * MIN(x[i], x[j]);
      if (v > mx) {
        mxl = i;
        mxr = j;
        mx = v;
      }
    }
  }
  printf("%d %d\n", mxl, mxr);
  printf("%ld\n", mx);
  return 0;
}
