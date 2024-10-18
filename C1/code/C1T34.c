#include <stdio.h>
#include <stdlib.h>

typedef struct card {
  int l, k;
  int idx;
  int r, p;
} card;

int cmp_card(const void *ap, const void *bp) {
  card a = *(card*)ap;
  card b = *(card*)bp;
  if (a.k != b.k) return b.k - a.k;
  if (a.l != b.l) return b.l - a.l;
  return a.idx - b.idx;
}

int cmp_idx(const void *ap, const void *bp) {
  card a = *(card*)ap;
  card b = *(card*)bp;
  return a.idx - b.idx;
}

int main() {
  int n;
  scanf("%d", &n);
  int h = 0;
  for (int count = 2; count <= n; count += (h + 1) * 3 - 1) h++;
  if (!h) {
    printf("Oh No, I Have No Friends TT\n");
    return 0;
  }
  card c[n];
  for (int i = 0; i < n; i++) {
    c[i].idx = i;
    c[i].r = 0;
    c[i].p = 0;
    char l;
    scanf(" %c", &l);
    switch (l) {
      case 'A':
        c[i].l = 14;
        break;
      case 'K':
        c[i].l = 13;
        break;
      case 'Q':
        c[i].l = 12;
        break;
      case 'J':
        c[i].l = 11;
        break;
      case '1':
        c[i].l = 10;
        scanf("0");
        break;
      default:
        c[i].l = l - '0';
        break;
    }
    char k;
    scanf(" %c", &k);
    switch (k) {
      case 'S':
        c[i].k = 4;
        break;
      case 'H':
        c[i].k = 3;
        break;
      case 'D':
        c[i].k = 2;
        break;
      case 'C':
        c[i].k = 1;
        break;
    }
  }
  qsort(c, n, sizeof(card), cmp_card);
  int p = 0;
  for (int i = 1; i <= h; i++) {
    for (int j = 1; j <= (h - i + 1) * 3 - 1; j++) {
      c[p].r = i;
      c[p].p = j;
      p++;
    }
  }
  qsort(c, n, sizeof(card), cmp_idx);
  printf("%d\n", h);
  for (int i = 0; i < n; i++) {
    if (c[i].r) {
      printf("%d %d\n", c[i].r, c[i].p);
    } else {
      printf("Eh?\n");
    }
  }
  return 0;
}
