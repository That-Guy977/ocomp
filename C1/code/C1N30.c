#include <stdio.h>
#include <string.h>

int main() {
  char str[100001];
  scanf("%s", str);
  int len = strlen(str);
  int palin = 1;
  for (int i = 0; i < len / 2; i++) {
    if (str[i] != str[len - i - 1]) {
      palin = 0;
      break;
    }
  }
  if (palin) {
    printf("YES\n");
  } else {
    printf("NO\n");
  }
  return 0;
}
