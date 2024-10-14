#include <stdio.h>

int main() {
  int n[10];
  for (int i = 0; i < 10; i++) {
    scanf("%d", &n[i]);
  }
  int sum = 0;
  for (int i = 0; i < 10; i++) {
    if (n[i] % 2 == 0) {
      sum += n[i];
    }
  }
  printf("%d\n", sum);
  return 0;
}
