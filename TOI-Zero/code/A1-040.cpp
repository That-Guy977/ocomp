#include <iostream>

using namespace std;

int main() {
  int cal = 0;
  while (true) {
    int op;
    cin >> op;
    switch (op) {
      case 1:
        cal += 100;
        break;
      case 2:
        cal += 120;
        break;
      case 3:
        cal += 200;
        break;
      case 4:
        cal += 60;
        break;
      case 5:
        goto end;
    }
  }
  end:;
  cout << "Bye Bye" << endl;
  cout << "Total Calories: " << cal << endl;
  return 0;
}
