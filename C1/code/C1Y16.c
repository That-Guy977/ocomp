#include <stdio.h>
#include <ctype.h>

int main() {
  char c;
  scanf("%c", &c);
  if (tolower(c) == 'y' || tolower(c) == 'n') {
    printf("yes\n");
  } else {
    printf("no\n");
  }
  return 0;
}
