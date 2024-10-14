#include <stdio.h>

int main() {
  long h, l;
  int n;
  scanf("%ld %ld %d", &h, &l, &n);
  int mxcount = 0;
  int count = 0;
  long mxpos = 0;
  long pos = 0;
  for (int i = 0; i < n; i++) {
    long x;
    scanf("%ld", &x);
    if (x < l || x > l + h) continue;
    if (x == pos) {
      count++;
    } else {
      if (count > mxcount) {
        mxcount = count;
        mxpos = pos;
      }
      pos = x;
      count = 1;
    }
  }
  if (count > mxcount) {
    mxcount = count;
    mxpos = pos;
  }
  printf("%d %ld\n", mxcount, mxpos);
  return 0;
}
