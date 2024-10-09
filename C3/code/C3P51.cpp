#include <iostream>
#include <algorithm>

using namespace std;

int main() {
  int n, b;
  cin >> n >> b;
  int c[n], p[n];
  for (int i = 0; i < n; i++) {
    cin >> c[i] >> p[i];
  }
  int *prev = new int[b + 1]{};
  int *curr = new int[b + 1]{};
  for (int i = 0; i < n; i++) {
    for (int j = 1; j <= b; j++) {
      curr[j] = max(prev[j], c[i] <= j ? prev[j - c[i]] + p[i] : 0);
    }
    delete[] prev;
    prev = curr;
    curr = new int[b + 1]{};
  }
  cout << prev[b] << endl;
  return 0;
}
