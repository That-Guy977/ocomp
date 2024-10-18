#include <stdio.h>

int main() {
  int n;
  scanf("%d", &n);
  int m[n];
  int k[n][100];
  for (int i = 0; i < n; i++) {
    scanf("%d", &m[i]);
    for (int j = m[i] - 1; j >= 0; j--) {
      scanf("%d", &k[i][j]);
    }
  }
  int mxh = 0;
  int h[n];
  int w[n];
  for (int i = 0; i < n; i++) {
    h[i] = 0;
    w[i] = 0;
    for (int j = 0; j < m[i]; j++) {
      h[i] += k[i][j] + 2;
      int ww = k[i][j] * 2 + 3;
      if (ww > w[i]) w[i] = ww;
    }
    if (h[i] > mxh) mxh = h[i];
  }
  int b[n];
  int r[n];
  int t[n];
  for (int i = 0; i < n; i++) {
    b[i] = -1;
    r[i] = 0;
    t[i] = 0;
  }
  for (int l = 0; l < mxh; l++) {
    for (int i = 0; i < n; i++) {
      if (l < mxh - h[i]) {
        for (int l = 0; l < w[i]; l++) printf(" ");
      } else if (r[i] == 0) {
        b[i]++;
        r[i] = k[i][b[i]] + 2;
        t[i] = 0;
        for (int j = 0; j < (w[i] - k[i][b[i]] * 2 - 1) / 2; j++) printf(" ");
        for (int j = 0; j < k[i][b[i]] * 2 + 1; j++) printf("_");
        for (int j = 0; j < (w[i] - k[i][b[i]] * 2 - 1) / 2; j++) printf(" ");
        r[i]--;
      } else {
        for (int j = 0; j < (w[i] - k[i][b[i]] * 2 - 3) / 2; j++) printf(" ");
        printf("|");
        for (int j = 0; j < r[i] - 1; j++) printf(" ");
        if (r[i] == k[i][b[i]] + 1) printf("^");
        else {
          printf("/");
          for (int j = 0; j < k[i][b[i]] * 2 - r[i] * 2 + 1; j++) printf("%c", t[i]++ % 26 + 'A');
          printf("\\");
        }
        for (int j = 0; j < r[i] - 1; j++) printf(" ");
        printf("|");
        for (int j = 0; j < (w[i] - k[i][b[i]] * 2 - 3) / 2; j++) printf(" ");
        r[i]--;
      }
    }
    printf("\n");
  }
  return 0;
}
