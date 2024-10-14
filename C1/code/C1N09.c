#include <stdio.h>

int main() {
  double m, f, h;
  scanf("%lf %lf %lf", &m, &f, &h);
  double score = m * 0.4 + f * 0.5 + h * 0.1;
  if (score >= 80) printf("G\n");
  else if (score >= 50) printf("P\n");
  else printf("F\n");
  return 0;
}
