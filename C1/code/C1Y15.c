#include <stdio.h>
#include <ctype.h>
#include <string.h>

int main() {
  char str[101];
  scanf("%[^\n]", str);
  int len = strlen(str);
  int ch = 0;
  int dg = 0;
  int sp = 0;
  for (int i = 0; i < len; i++) {
    if (isalpha(str[i])) ch++;
    else if (isdigit(str[i])) dg++;
    else sp++;
  }
  printf("Number of Alphabets in the string is : %d\n", ch);
  printf("Number of Digits in the string is : %d\n", dg);
  printf("Number of Special characters in the string is : %d\n", sp);
  return 0;
}
