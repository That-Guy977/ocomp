#include <stdio.h>

int main() {
  char x[3];
  for (int i = 0; i < 3; i++) {
    scanf(" %c", &x[i]);
  }
  while (1) {
    char t, d;
    scanf(" %c %c", &t, &d);
    if (t == 'X') break;
    int i = t - 'A';
    int s = d == 'R' ? 1 : -1;
    int p = i + s;
    if (0 <= p && p < 3) {
      char temp = x[i];
      x[i] = x[p];
      x[p] = temp;
    }
  }
  for (int i = 0; i < 3; i++) {
    switch (x[i]) {
      case 'T':
        printf("Triangle\n");
        break;
      case 'C':
        printf("Candy\n");
        break;
      case 'S':
        printf("Star\n");
        break;
    }
  }
  return 0;
}
