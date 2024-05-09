#include <iostream>
#include <queue>

using namespace std;

int main() {
  int n;
  cin >> n;
  priority_queue<int> cart;
  for (int i = 0; i < n; i++) {
    int c;
    cin >> c;
    cart.push(c);
  }
  long total = 0;
  while (!cart.empty()) {
    total += cart.top();
    cart.pop();
    if (!cart.empty()) {
      total += cart.top();
      cart.pop();
    }
    if (!cart.empty()) {
      cart.pop();
    }
  }
  cout << total << endl;
  return 0;
}
