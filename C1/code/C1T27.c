#include <stdio.h>
#define MIN(a, b) (a < b ? a : b)

int solve(int, int, int, int[*][*]);

int main() {
  int n, m;
  scanf("%d %d", &n, &m);
  int p[n];
  for (int i = 0; i < n; i++) {
    int floor[m][m];
    for (int j = 0; j < m; j++) {
      for (int k = 0; k < m; k++) {
        scanf("%d", &floor[j][k]);
      }
    }
    p[i] = solve(m, 0, 0, floor);
  }
  int q;
  scanf("%d", &q);
  for (int i = 0; i < q; i++) {
    int pow;
    scanf("%d", &pow);
    int f;
    for (f = 0; f < n; f++) {
      if (pow < p[f]) break;
      pow -= p[f];
    }
    if (f == n) {
      printf("Cleared\n");
    } else {
      printf("%d\n", f + 1);
    }
  }
  return 0;
}

int solve(int m, int x, int y, int floor[m][m]) {
  static int memo[100][100];
  if (!x && !y) {
    for (int i = 0; i < m; i++) {
      for (int j = 0; j < m; j++) {
        memo[i][j] = 0;
      }
    }
  }
  if (memo[x][y] != 0) return memo[x][y];
  int mn = 0;
  if (x < m - 1) {
    int next = solve(m, x + 1, y, floor);
    if (!mn || next < mn) mn = next;
  }
  if (y < m - 1) {
    int next = solve(m, x, y + 1, floor);
    if (!mn || next < mn) mn = next;
  }
  int res = floor[x][y] + mn;
  memo[x][y] = res;
  return res;
}
