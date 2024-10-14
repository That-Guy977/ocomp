#include <stdio.h>
#include <ctype.h>
#include <string.h>

int main() {
  char str[101];
  scanf("%[^\n]", str);
  int key;
  scanf("%d", &key);
  int len = strlen(str);
  for (int i = 0; i < len; i++) {
    if (isalpha(str[i])) {
      printf("%c", (str[i] - 'a' - key + 26) % 26 + 'a');
    } else printf("%c", str[i]);
  }
  printf("\n");
  return 0;
}
