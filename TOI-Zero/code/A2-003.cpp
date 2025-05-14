#include <iostream>

using namespace std;

int main() {
  int n;
  cin >> n;
  int count = 0;
  int pprev = 0;
  int prev = 0;
  for (int i = 0; i < n; i++) {
    int h;
    cin >> h;
    if (prev > pprev && prev > h) count++;
    pprev = prev;
    prev = h;
  }
  if (prev > pprev) count++;
  cout << count << endl;
  return 0;
}
