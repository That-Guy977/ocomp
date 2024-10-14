#include <stdio.h>
#include <string.h>

int main() {
  int n;
  scanf("%d", &n);
  int d[5];
  for (int i = 4; i >= 0; i--) {
    d[i] = n % 10;
    n /= 10;
  }
  if (d[0] > 5) printf("1");
  else if (d[1] > 5) printf("2");
  else if (d[2] > 5) printf("3");
  else if (d[3] > 5) printf("4");
  else if (d[4] > 5) printf("5");
  else printf("0");
  if (d[0] == d[4] && d[1] == d[3]) {
    if (d[0] + d[4] > 5) printf("1");
    else if (d[1] + d[3] > 5) printf("2");
    else printf("0");
  } else {
    if (d[3] && d[0] / d[3] > 5) printf("1");
    else if (d[1] - d[4] > 5) printf("2");
    else printf("0");
  }
  int sum = 0;
  int prod = 1;
  for (int i = 0; i < 4; i++) {
    sum += d[i];
    prod *= d[i];
  }
  if (sum > 25) printf("1");
  else if (prod > 55) printf("2");
  else printf("0");
  printf("\n");
  return 0;
}
