#include <stdio.h>
#include <stdlib.h>
#define MIN(a, b) (a < b ? a : b)

int main() {
  int n;
  scanf("%d", &n);
  int h, m;
  scanf("%d:%d", &h, &m);
  int t = h * 60 + m;
  int dt = 0;
  for (int i = 0; i < n; i++) {
    int hp, mp;
    scanf("%d:%d", &hp, &mp);
    int tp = hp * 60 + mp;
    dt += MIN(abs(t - tp), 720 - abs(t - tp));
  }
  printf("%d\n", dt);
  return 0;
}
