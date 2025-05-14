#include <iostream>
#include <string>

using namespace std;

int main() {
  string msg;
  cin >> msg;
  char curr = msg[0];
  int count = 0;
  for (char ch : msg) {
    if (ch != curr) {
      cout << count << curr;
      curr = ch;
      count = 0;
    }
    count++;
  }
  cout << count << curr;
  cout << endl;
  return 0;
}
