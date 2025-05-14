#include <iostream>
#include <string>

using namespace std;

int main() {
  int n;
  cin >> n;
  int count = 0;
  int mxw;
  string mxn;
  cin >> mxn >> mxw;
  if (mxw > 15) count++;
  for (int i = 1; i < n; i++) {
    string name;
    int w;
    cin >> name >> w;
    if (w > mxw) {
      mxw = w;
      mxn = name;
    }
    if (w > 15) count++;
  }
  cout << count << endl;
  cout << mxn << " " << mxw << endl;
  return 0;
}
