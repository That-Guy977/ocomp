#include <iostream>

using namespace std;

int main() {
  int n;
  cin >> n;
  int mx = 0;
  int a[n];
  int l[n];
  for (int i = 0; i < n; i++) {
    cin >> a[i];
    int submx = 0;
    for (int j = 0; j < i; j++) {
      if (a[j] < a[i] && l[j] > submx) {
        submx = l[j];
      }
    }
    submx++;
    l[i] = submx;
    if (submx > mx) mx = submx;
  }
  cout << mx << endl;
  return 0;
}
