#include <stdio.h>
#include <ctype.h>
#include <string.h>

int main() {
  char s[1001];
  scanf("%[^\n]", s);
  int len = strlen(s);
  int lower = 0;
  int upper = 0;
  for (int i = 0; i < len; i++) {
    if (islower(s[i])) lower++;
    if (isupper(s[i])) upper++;
  }
  if (lower > upper) {
    printf("Change Upper to Lower : %d\n", upper);
  } else if (lower < upper) {
    printf("Change Lower to Upper : %d\n", lower);
  } else {
    printf("Change to Both : %d\n", lower);
  }
  return 0;
}
