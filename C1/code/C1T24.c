#include <stdio.h>
#define MAX(a, b) (a > b ? a : b)
#define MIN(a, b) (a < b ? a : b)

typedef struct object {
  int x, y;
  char type;
  int k;
  int used;
} object;

unsigned fight(int, int, int, int, int, object[*]);

int main() {
  int n, dk, dx, dy;
  scanf("%d %d %d %d", &n, &dk, &dx, &dy);
  int t;
  scanf("%d", &t);
  object objs[t + 1];
  for (int i = 0; i < t; i++) {
    int x, y;
    char type;
    int k;
    scanf("%d %d %c %d", &x, &y, &type, &k);
    objs[i] = (object){ x, y, type, k, 0 };
  }
  objs[t] = (object){ dx, dy, 'D', dk, 0 };
  printf("%d\n", fight(n, 0, 0, 0, t + 1, objs));
  return 0;
}

unsigned fight(int n, int x, int y, int k, int t, object objs[t]) {
  unsigned res = -1;
  for (int i = 0; i < t; i++) {
    object *obj = &objs[i];
    if (!obj->used && x <= obj->x && y <= obj->y) {
      unsigned next = 0;
      switch (obj->type) {
        case 'A':
          obj->used = 1;
          next += fight(n, obj->x, obj->y, k + obj->k, t, objs);
          obj->used = 0;
          break;
        case 'B':
          obj->used = 1;
          next += fight(n, obj->x, obj->y, k * obj->k, t, objs);
          obj->used = 0;
          break;
        case 'C':
          obj->used = 1;
          unsigned mn = -1;
          for (int nx = MAX(obj->x - obj->k, 0); nx <= MIN(obj->x + obj->k, n - 1); nx++) {
            for (int ny = MAX(obj->y - obj->k, 0); ny <= MIN(obj->y + obj->k, n - 1); ny++) {
              unsigned warp = fight(n, nx, ny, k, t, objs);
              if (warp < mn) mn = warp;
            }
          }
          next += mn;
          obj->used = 0;
          break;
        case 'D':
          if (k < obj->k && obj->k > 1) {
            int dk = obj->k;
            obj->k /= 2;
            next += fight(n, 0, 0, k, t, objs);
            obj->k = dk;
          }
          break;
      }
      if (next == -1) continue;
      next += (obj->x - x) + (obj->y - y);
      if (next < res) res = next;
    }
  }
  return res;
}
