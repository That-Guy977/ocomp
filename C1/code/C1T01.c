#include <stdio.h>
#include <string.h>
#define MAX(a, b) (a > b ? a : b)

int main() {
  char n[1000002];
  char m[1000002];
  char k[1000002];
  scanf("%s %s %s", n, m, k);
  int nlen = strlen(n);
  int mlen = strlen(m);
  int klen = strlen(k);
  for (int i = 0; i < nlen / 2; i++) {
    char temp = n[i];
    n[i] = n[nlen - i - 1];
    n[nlen - i - 1] = temp;
  }
  for (int i = 0; i < mlen / 2; i++) {
    char temp = m[i];
    m[i] = m[mlen - i - 1];
    m[mlen - i - 1] = temp;
  }
  for (int i = 0; i < klen / 2; i++) {
    char temp = k[i];
    k[i] = k[klen - i - 1];
    k[klen - i - 1] = temp;
  }
  char s[1000002];
  int slen = 0;
  int carry = 0;
  while (slen < MAX(nlen, mlen) || carry) {
    int sum = (slen < nlen ? n[slen] - '0' : 0) + (slen < mlen ? m[slen] - '0': 0) + carry;
    s[slen++] = sum % 10 + '0';
    carry = sum / 10;
  }
  s[slen] = 0;
  char r[1000002];
  int rlen = 0;
  int neg = 0;
  if (slen > klen) neg = 0;
  else if (slen < klen) neg = 1;
  else {
    int p = slen - 1;
    while (p > 0 && s[p] == k[p]) p--;
    if (s[p] >= k[p]) neg = 0;
    else neg = 1;
  }
  while (rlen < MAX(slen, klen) || carry && rlen < 20) {
    int diff = (neg ? -1 : 1) * ((rlen < slen ? s[rlen] - '0' : 0) - (rlen < klen ? k[rlen] - '0': 0)) - carry;
    r[rlen++] = (diff + 10) % 10 + '0';
    carry = diff < 0;
  }
  if (neg) printf("-");
  int zero = 1;
  for (int i = rlen - 1; i >= 0; i--) {
    if (!zero || r[i] != '0') {
      printf("%c", r[i]);
      zero = 0;
    }
  }
  if (zero) printf("0");
  printf("\n");
  return 0;
}
