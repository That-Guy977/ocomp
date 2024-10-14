#include <stdio.h>
#include <ctype.h>
#include <string.h>

int main() {
  char str[10001];
  scanf("%s", str);
  int len = strlen(str);
  int upper = 0;
  int lower = 0;
  for (int i = 0; i < len; i++) {
    if (isupper(str[i])) upper++;
    else lower++;
  }
  printf("[%d]", upper + lower);
  if (lower == 0) printf("All Capital Letter\n");
  else if (upper == 0) printf("All Small Letter\n");
  else printf("Mix\n");
  return 0;
}
