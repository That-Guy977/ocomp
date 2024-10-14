#include <stdio.h>
#include <string.h>

int main() {
  char str[101];
  scanf("%[^\n]", str);
  int len = strlen(str);
  int palin = 1;
  for (int i = 0; i < len / 2; i++) {
    if (str[i] != str[len - i - 1]) {
      palin = 0;
      break;
    }
  }
  printf("%s is %sa palindrome\n", str, palin ? "" : "not ");
  return 0;
}
