#include <iostream>
#include <map>
#include <set>

using namespace std;

struct customer {
  int i;
  int s;
  int idx;
  bool operator<(const customer &other) const {
    if (s != other.s) return s > other.s;
    return idx < other.idx;
  }
};

typedef set<customer>::iterator customer_it;

int main() {
  int n;
  cin >> n;
  set<customer> customers;
  map<int, customer_it> index;
  for (int idx = 0; idx < n; idx++) {
    int op;
    cin >> op;
    int i, s;
    switch (op) {
      case 1: {
        cin >> i >> s;
        index[i] = customers.insert({ i, s, idx }).first;
        break;
      }
      case 2: {
        cin >> i >> s;
        customer_it it = index[i];
        customer c = *it;
        customers.erase(it);
        c.s = s;
        index[i] = customers.insert(c).first;
        break;
      }
      case 3: {
        if (!customers.empty()) {
          customer_it it = customers.begin();
          cout << it->i;
          customers.erase(it);
        } else {
          cout << "no customer";
        }
        cout << endl;
        break;
      }
    }
  }
  return 0;
}
