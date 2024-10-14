#include <stdio.h>

int main() {
  int n;
  scanf("%d", &n);
  printf("%d\n", n / 1000);
  n %= 1000;
  printf("%d\n", n / 500);
  n %= 500;
  printf("%d\n", n / 100);
  n %= 100;
  printf("%d\n", n / 50);
  n %= 50;
  printf("%d\n", n / 20);
  n %= 20;
  printf("%d\n", n / 10);
  n %= 10;
  printf("%d\n", n / 5);
  n %= 5;
  printf("%d\n", n);
  return 0;
}
