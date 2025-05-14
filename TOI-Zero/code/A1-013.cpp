#include <iostream>

using namespace std;

int main() {
  char key;
  int code;
  cin >> key >> code;
  bool keyCorrect = key == 'H';
  bool codeCorrect = code == 4567;
  cout << "safe ";
  if (keyCorrect && codeCorrect) {
    cout << "unlocked";
  } else {
    cout << "locked";
    if (keyCorrect) {
      cout << " - change digit";
    }
    if (codeCorrect) {
      cout << " - change char";
    }
  }
  cout << endl;
  return 0;
}
