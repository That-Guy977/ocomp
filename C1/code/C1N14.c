#include <stdio.h>
#include <ctype.h>
#include <string.h>

int main() {
  char s[2001];
  scanf("%s", s);
  int len = strlen(s);
  for (int i = 0; i < len; i++) {
    printf("%c", i % 2 == 0 ? toupper(s[i]) : tolower(s[i]));
  }
  printf("\n");
  return 0;
}
