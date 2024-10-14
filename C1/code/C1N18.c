#include <stdio.h>
#include <string.h>

int main() {
  char n[10];
  scanf("%s", n);
  int len = strlen(n);
  for (int i = 0; i < len; i++) {
    if (i) printf(" ");
    switch (n[i]) {
      case '0':
        printf("zero");
        break;
      case '1':
        printf("one");
        break;
      case '2':
        printf("two");
        break;
      case '3':
        printf("three");
        break;
      case '4':
        printf("four");
        break;
      case '5':
        printf("five");
        break;
      case '6':
        printf("six");
        break;
      case '7':
        printf("seven");
        break;
      case '8':
        printf("eight");
        break;
      case '9':
        printf("nine");
        break;
    }
  }
  printf("\n");
  return 0;
}
