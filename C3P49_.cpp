#include <iostream>
#include <algorithm>

using namespace std;

int main() {
  int n;
  cin >> n;
  int a[n];
  unsigned int mins[n];
  for (int i = 0; i < n; i++) {
    cin >> a[i];
    mins[i] = -1;
  }
  for (int i = 0; i < n; i++) {
    for (int j = 0; j < n - i; j++) {
      if (a[j + i] < mins[j]) {
        mins[j] = a[j + i];
      }
    }
    cout << *max_element(mins, mins + n - i) << " ";
  }
  cout << endl;
  return 0;
}
