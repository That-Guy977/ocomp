#include <iostream>
#include <string>

using namespace std;

const string seq = "RGB";
const string seqn[] = {
  "Red",
  "Green",
  "Blue",
};

int main() {
  char c;
  int n;
  cin >> c >> n;
  int offset = seq.find(c);
  for (int i = 0; i < n; i++) {
    if (i) cout << " ";
    cout << seqn[(i + offset) % 3];
  }
  cout << endl;
  return 0;
}
