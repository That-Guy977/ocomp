#include <iostream>
#include <utility>

using namespace std;

int main() {
  int p, q;
  cin >> p >> q;
  int stack[p];
  for (int i = 0; i < p; i++) {
    cin >> stack[i];
  }
  for (int i = 0; i < q; i++) {
    int idx;
    cin >> idx;
    for (int i = 0; i * 2 < p - idx; i++) {
      swap(stack[idx + i], stack[p - i - 1]);
    }
  }
  for (int i = 0; i < p; i++) {
    cout << stack[i] << " ";
  }
  cout << endl;
  return 0;
}
