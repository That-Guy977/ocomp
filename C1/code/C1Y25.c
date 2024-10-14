#include <stdio.h>
#include <stdlib.h>

int upper(int a[], int q, int l, int r) {
  if (l >= r) return l;
  int mid = l + (r - l) / 2;
  if (q >= a[mid]) return upper(a, q, mid + 1, r);
  else return upper(a, q, l, mid);
}

int cmp(const void *ap, const void *bp) {
  int a = *(int*)ap;
  int b = *(int*)bp;
  return a - b;
}

int main() {
  int n, m;
  scanf("%d %d", &n, &m);
  int a[n];
  for (int i = 0; i < n; i++) {
    scanf("%d", &a[i]);
  }
  qsort(a, n, sizeof(int), cmp);
  for (int i = 0; i < m; i++) {
    int q;
    scanf("%d", &q);
    printf("%d\n", upper(a, q, 0, n));
  }
  return 0;
}
