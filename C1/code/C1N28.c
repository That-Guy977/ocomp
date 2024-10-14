#include <stdio.h>

int main() {
  int num[5];
  for (int i = 0; i < 5; i++) {
    scanf("%d", &num[i]);
  }
  int mx = num[0];
  int mn = num[0];
  for (int i = 1; i < 5; i++) {
    if (num[i] > mx) mx = num[i];
    if (num[i] < mn) mn = num[i];
  }
  printf("%d\n", mn);
  printf("%d\n", mx);
  return 0;
}
