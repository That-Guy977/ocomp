#include <stdio.h>
#include <ctype.h>

int main() {
  int c;
  scanf("%c", &c);
  if (isalpha(c)) printf("Character\n");
  else if (isdigit(c)) printf("Number\n");
  else printf("Special Characters\n");
  return 0;
}
