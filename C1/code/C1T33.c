#include <stdio.h>

int main() {
  int n;
  scanf("%d", &n);
  char s[n][6];
  int c[n], d[n];
  for (int i = 0; i < n; i++) {
    scanf(" %s %d %d", s[i], &c[i], &d[i]);
  }
  char guess[6];
  guess[5] = '\0';
  for (guess[0] = 'A'; guess[0] <= 'Z'; guess[0]++) {
    for (guess[1] = 'A'; guess[1] <= 'Z'; guess[1]++) {
      for (guess[2] = 'A'; guess[2] <= 'Z'; guess[2]++) {
        for (guess[3] = 'A'; guess[3] <= 'Z'; guess[3]++) {
          for (guess[4] = 'A'; guess[4] <= 'Z'; guess[4]++) {
            int valid = 1;
            for (int i = 0; i < n && valid; i++) {
              int gc = 0;
              int gd = 0;
              int gt[5];
              int st[5];
              for (int j = 0; j < 5; j++) {
                if (guess[j] == s[i][j]) {
                  gc++;
                  gt[j] = 1;
                  st[j] = 1;
                } else {
                  gt[j] = 0;
                  st[j] = 0;
                }
              }
              if (gc != c[i]) goto invalid;
              for (int j = 0; j < 5; j++) {
                for (int k = 0; k < 5 && !gt[j]; k++) {
                  if (st[k]) continue;
                  if (guess[j] == s[i][k]) {
                    gd++;
                    gt[j] = 1;
                    st[k] = 1;
                  }
                }
              }
              if (gd != d[i]) goto invalid;
              continue;
              invalid:
              valid = 0;
            }
            if (valid) printf("%s\n", guess);
          }
        }
      }
    }
  }
  return 0;
}
