#include <iostream>
#include <map>

using namespace std;

const map<char, char> pairs {
  { 'A', 'T' },
  { 'T', 'A' },
  { 'C', 'G' },
  { 'G', 'C' },
};

int main() {
  int n;
  cin >> n;
  char a[n];
  for (int i = 0; i < n; i++) {
    cin >> a[i];
  }
  char b[n];
  for (int i = 0; i < n; i++) {
    cin >> b[i];
  }
  int c;
  cin >> c;
  for (int i = 0; i < c; i++) {
    int s, p;
    char nt;
    cin >> s >> p >> nt;
    if (s == 1) {
      a[p] = nt;
    } else {
      b[p] = nt;
    }
  }
  int mismatch = 0;
  for (int i = 0; i < n; i++) {
    if (b[i] != pairs.at(a[i])) {
      mismatch++;
    }
  }
  for (int i = 0; i < n; i++) {
    if (i) cout << " ";
    cout << a[i];
  }
  cout << endl;
  for (int i = 0; i < n; i++) {
    if (i) cout << " ";
    cout << b[i];
  }
  cout << endl;
  cout << mismatch << endl;
  return 0;
}
