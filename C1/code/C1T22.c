#include <stdio.h>

int main() {
  int nx, ny, nz, n;
  scanf("%d %d %d %d", &nx, &ny, &nz, &n);
  for (int t = 0; t < n; t += nx * ny * nz) {
    long total = 0;
    for (int z = 0; z < nz; z++) {
      int tz = z * ny * nx;
      int revv = z % 2;
      for (int y = 0; y < ny; y++) {
        int ty = y * nx;
        int revh = (y % 2) != revv;
        for (int x = 0; x < nx; x++) {
          int tx = x;
          if (x) printf(" ");
          int id = t + tz;
          if (!revv) id += ty;
          else id += (ny - 1) * nx - ty;
          if (!revh) id += tx;
          else id += nx - 1 - tx;
          if (id < n) {
            total += id;
            printf("%d", id);
          } else {
            printf("v");
          }
        }
        printf("\n");
      }
    }
    printf("%ld\n", total);
  }
  return 0;
}
