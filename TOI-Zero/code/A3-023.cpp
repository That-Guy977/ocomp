#include <iostream>
#include <algorithm>
#include <iterator>
#include <vector>
#define iter(c) c.begin(), c.end()

using namespace std;

int main() {
  int a, b;
  cin >> a >> b;
  vector<int> primes { 2 };
  for (int p = 3; p <= b * 3; p += 2) {
    for (int i = 1; i < primes.size() && primes[i] * primes[i] <= p; i++) {
      if (p % primes[i] == 0) {
        goto next;
      }
    }
    primes.push_back(p);
    next:;
  }
  long count = 0;
  auto start = lower_bound(iter(primes), a * 3);
  auto end = upper_bound(iter(primes), b * 3);
  for (auto it = start; it != end; ++it) {
    int p = *it;
    for (int i = max(a, p - b * 2); i <= p / 3; i++) {
      int s = p - i;
      count += s / 2 - max(i, s - b) + 1;
    }
  }
  cout << count << endl;
  return 0;
}
