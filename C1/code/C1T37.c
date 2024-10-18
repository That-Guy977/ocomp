#include <stdio.h>

long gcd(long, long);
long xgcd(long, long);

long encrypt(long, long, long, long);
long decrypt(long, long, long, long);

int main() {
  int t;
  scanf("%d", &t);
  for (int ti = 0; ti < t; ti++) {
    char k[8];
    scanf(" %s", k);
    long mc, p, q, e;
    scanf("%ld %ld %ld %ld", &mc, &p, &q, &e);
    long n = p * q;
    long phi = (p - 1) * (q - 1);
    if (e >= phi || gcd(phi, e) != 1) printf("Error\n");
    else {
      switch (k[0]) {
        case 'E':
          printf("%lX\n", encrypt(mc, e, n, phi));
          break;
        case 'D':
          printf("%lX\n", decrypt(mc, e, n, phi));
          break;
      }
    }
  }
  return 0;
}

long encrypt(long m, long e, long n, long phi) {
  long c = 1;
  m %= n;
  for (int i = 0; i < e; i++) {
    c *= m;
    c %= n;
  }
  return c;
}

long decrypt(long c, long e, long n, long phi) {
  long d = (xgcd(e, phi) % phi + phi) % phi;
  long m = 1;
  c %= n;
  for (int i = 0; i < d; i++) {
    m *= c;
    m %= n;
  }
  return m;
}

long gcd(long a, long b) {
  while (b) {
    long temp = b;
    b = a % b;
    a = temp;
  }
  return a;
}

long xgcd(long a, long b) {
  long x = 1;
  long y = 0;
  while (b) {
    long temp;
    temp = y;
    y = x - (a / b) * y;
    x = temp;
    temp = b;
    b = a % b;
    a = temp;
  }
  return x;
}
