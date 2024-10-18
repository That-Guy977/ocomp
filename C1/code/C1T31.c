#include <stdio.h>

int main() {
  int d, e;
  scanf("%d %d", &d, &e);
  int work = 0;
  for (int i = 0; i < d; i++) {
    int t;
    scanf("%d", &t);
    work += t;
    e -= work;
  }
  if (e >= 0) printf("Success ");
  else printf("Fail ");
  printf("%d\n", e);
  return 0;
}
