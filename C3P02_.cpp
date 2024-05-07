#include <iostream>
#include <algorithm>
#include <functional>
#include <vector>
#include <map>
#include <string>

#define BITSET_TYPE unsigned long
#define BITSET_WIDTH (int)(8*sizeof(BITSET_TYPE))

using namespace std;

map<char, function<void(BITSET_TYPE&, BITSET_TYPE)>> ops = {
  { 'F', [](auto &a, auto b) { a |= b; } },
  { 'E', [](auto &a, auto b) { a &= ~b; } },
  { 'I', [](auto &a, auto b) { a ^= b; } },
};

int main() {
  unsigned long x = 1ul << 63 << 1;
  int n = 0;
  int m;
  cin >> m;
  vector<BITSET_TYPE> fan;
  for (int i = 0; i < m; i++) {
    int t;
    string p;
    cin >> t >> p;
    int s = t * p.length();
    for (int j = 0; j < t; j++) {
      for (int k = 0; k < p.length(); k++) {
        if (n % BITSET_WIDTH == 0) fan.push_back(0);
        fan.back() |= (BITSET_TYPE)(p[k] == '1') << n % BITSET_WIDTH;
        n++;
      }
    }
  }
  int q;
  cin >> q;
  for (int i = 0; i < q; i++) {
    char op;
    int a, b;
    cin >> op >> a >> b;
    if (ops.count(op)) {
      int firstset = a / BITSET_WIDTH + (a % BITSET_WIDTH != 0);
      int lastset = b / BITSET_WIDTH;
      for (int i = firstset; i < lastset; i++) {
        ops[op](fan[i], ~0);
      }
      if (a % BITSET_WIDTH) {
        int firststop = min(b, firstset * BITSET_WIDTH - 1) % BITSET_WIDTH;
        ops[op](fan[firstset - 1], ~((1 << a % BITSET_WIDTH) - 1) & (2 << firststop) - 1);
      }
      if (b >= firstset * BITSET_WIDTH) {
        ops[op](fan[lastset], (2 << b % BITSET_WIDTH) - 1);
      }
    } else {
      int count = 0;
      for (int i = a; i <= b; i++) {
        count += (fan[i / BITSET_WIDTH] & 1 << i % BITSET_WIDTH) != 0;
      }
      cout << count << endl;
    }
  }
  return 0;
}
