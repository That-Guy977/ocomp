#include <stdio.h>
#include <stdlib.h>
#define MAX(a, b) (a > b ? a : b)

int main() {
  int n;
  scanf("%d", &n);
  int h = 0;
  int w = 0;
  int canvas[100][100];
  for (int i = 0; i < 100; i++) {
    for (int j = 0; j < 100; j++) {
      canvas[i][j] = 0;
    }
  }
  for (int i = 0; i < n; i++) {
    int x, y, r;
    char t;
    scanf("%d %d %c %d", &x, &y, &t, &r);
    x--;
    y--;
    switch (t) {
      case 'S':
        for (int i = -r; i <= r; i++) {
          canvas[MAX(y - r, 0)][MAX(x + i, 0)]++;
          canvas[MAX(y + r, 0)][MAX(x + i, 0)]++;
          canvas[MAX(y + i, 0)][MAX(x - r, 0)]++;
          canvas[MAX(y + i, 0)][MAX(x + r, 0)]++;
        }
        if (x + r > w) w = x + r;
        if (y + r > h) h = y + r;
        break;
      case 'T':
        for (int i = -r; i <= r; i++) {
          canvas[MAX(y + r, 0)][MAX(x + i, 0)]++;
          canvas[MAX(y + abs(i), 0)][MAX(x + i, 0)]++;
        }
        if (x + r > w) w = x + r;
        if (y + r > h) h = y + r;
        break;
      case 'R':
        for (int i = -r; i <= r; i++) {
          canvas[MAX(y - r + abs(i), 0)][MAX(x + i, 0)]++;
          canvas[MAX(y + r - abs(i), 0)][MAX(x + i, 0)]++;
        }
        if (x + r > w) w = x + r;
        if (y + r > h) h = y + r;
        break;
    }
  }
  for (int i = 0; i <= h; i++) {
    for (int j = 0; j <= w; j++) {
      printf("%c", canvas[i][j] ? '*' : ' ');
    }
    printf("\n");
  }
  return 0;
}
