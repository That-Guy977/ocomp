#include <iostream>
#include <utility>

using namespace std;

void flip(int[], int, int);

int main() {
  int t, p;
  cin >> t >> p;
  for (int ti = 0; ti < t; ti++) {
    int stack[p];
    for (int i = 0; i < p; i++) {
      cin >> stack[i];
    }
    int sorted = 0;
    int flips = 0;
    while (sorted < p) {
      int maxIdx = sorted;
      for (int i = sorted; i < p; i++) {
        if (stack[i] > stack[maxIdx]) maxIdx = i;
      }
      if (maxIdx != sorted) {
        if (maxIdx != p - 1) {
          flip(stack, p, maxIdx);
          flips++;
        }
        flip(stack, p, sorted);
        flips++;
      }
      sorted++;
    }
    cout << flips << endl;
  }
  return 0;
}

void flip(int stack[], int p, int idx) {
  for (int i = 0; i * 2 < p - idx; i++) {
    swap(stack[idx + i], stack[p - i - 1]);
  }
}
