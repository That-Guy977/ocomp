#include <iostream>
#include <functional>

#define STEP 100

using namespace std;

int main() {
  int n, m;
  cin >> n >> m;
  int a[n], b[n], ax[n / STEP + 1];
  for (int i = 0; i < n; i++) {
    cin >> a[i];
    if (i % STEP == 0 || ax[i / STEP] < a[i]) {
      ax[i / STEP] = a[i];
    }
  }
  cin >> b[0];
  for (int i = 1; i < n; i++) {
    cin >> b[i];
    b[i] += b[i - 1];
  }
  function<int(int, int)> max_h = [&a, &ax](int s, int t) {
    int max = 0;
    int firstgroup = s / STEP + (s % STEP != 0);
    int lastgroup = t / STEP;
    for (int i = firstgroup; i < lastgroup; i++) {
      if (ax[i] > max) max = ax[i];
    }
    for (int i = s; i < firstgroup * STEP && i <= t; i++) {
      if (a[i] > max) max = a[i];
    }
    if (t >= firstgroup * STEP) {
      for (int i = lastgroup * STEP; i <= t; i++) {
        if (a[i] > max) max = a[i];
      }
    }
    return max;
  };
  for (int i = 0; i < m; i++) {
    int s, t;
    cin >> s >> t;
    cout << max_h(s, t) << " " << b[t] - b[s - 1] << endl;
  }
  return 0;
}
