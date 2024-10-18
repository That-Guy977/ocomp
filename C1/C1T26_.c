#include <stdio.h>

int main() {
  int n;
  scanf("%d", &n);
  char s[n+1];
  scanf(" %s", s);
  int mx = 2 << (n - 1);
  int u[mx];
  int uc = 0;
  for (int i = 1; i < mx; i++) {
    int first = 1;
    int v = 0;
    for (int j = 0; j < 5; j++) {
      if (i & (1 << j)) {
        if (v % 10 == s[j] - '0') goto end;
        v *= 10;
        v += s[j] - '0';
        first = 0;
      }
    }
    for (int j = 0; j < uc; j++) {
      if (v == u[j]) goto end;
    }
    u[uc++] = v;
    continue;
    end:;
  }
  for (int i = 0; i < n; i++) {
    if (s[i] == '0') {
      u[uc++] = 0;
      break;
    }
  }
  printf("%d\n", uc);
  for (int i = 0; i < uc; i++) {
    printf("%d\n", u[i]);
  }
  return 0;
}
