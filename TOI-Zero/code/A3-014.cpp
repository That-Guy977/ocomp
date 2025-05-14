#include <iostream>
#include <algorithm>

using namespace std;

int main() {
  int n;
  cin >> n;
  int over = 0;
  int rest = 0;
  for (int i = 0; i < n; i++) {
    int h;
    cin >> h;
    if (h > 18) over++;
    else rest++;
  }
  cout << over + max(rest, over - 1) << endl;
  return 0;
}
