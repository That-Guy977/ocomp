#include <iostream>
#include <cstring>

using namespace std;

int veins(int[], int, int, int);
void clear(int[], int, int, int, int, int, int);

int main() {
  int x, y, z;
  cin >> x >> y >> z;
  int m[x * y * z];
  int s[x * y * z];
  for (int i = 0; i < x * y * z; i++) {
    cin >> m[i];
  }
  memcpy(s, m, sizeof(s));
  cout << veins(s, x, y, z) << endl;
  int n;
  cin >> n;
  for (int ni = 0; ni < n; ni++) {
    int a, b, c, r;
    cin >> a >> b >> c >> r;
    for (int da = -r; da <= r; da++) {
      int i = a + da;
      if (i < 0 || i >= x) continue;
      for (int db = -r; db <= r; db++) {
        int j = b + db;
        if (j < 0 || j >= y) continue;
        for (int dc = -r; dc <= r; dc++) {
          int k = c + dc;
          if (k < 0 || k >= z) continue;
          m[(i * y + j) * z + k] = 0;
        }
      }
    }
  }
  memcpy(s, m, sizeof(s));
  cout << veins(s, x, y, z) << endl;
  return 0;
}

int veins(int m[], int x, int y, int z) {
  int res = 0;
  for (int i = 0; i < x * y * z; i++) {
    if (m[i]) {
      res++;
      clear(m, x, y, z, i / z / y, i / z % y, i % z);
    }
  }
  return res;
}

void clear(int m[], int x, int y, int z, int i, int j, int k) {
  if (i < 0 || i >= x || j < 0 || j >= y || k < 0 || k >= z) return;
  int p = (i * y + j) * z + k;
  if (!m[p]) return;
  m[p] = 0;
  for (int d = -1; d <= 1; d++) {
    clear(m, x, y, z, i + d, j, k);
  }
  for (int d = -1; d <= 1; d++) {
    clear(m, x, y, z, i, j + d, k);
  }
  for (int d = -1; d <= 1; d++) {
    clear(m, x, y, z, i, j, k + d);
  }
}
