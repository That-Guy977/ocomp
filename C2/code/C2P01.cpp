#include <iostream>
#include <string>
#include <vector>

using namespace std;

int main() {
  vector<vector<char>> stacks;
  string s;
  cin >> s;
  for (char& ch : s) {
    int min = -1;
    vector<char> *minStack = NULL;
    for (vector<char>& stack : stacks) {
      int d = stack.back() - ch;
      if (stack.back() >= ch && (min == -1 || d < min)) {
        min = d;
        minStack = &stack;
      }
    }
    if (minStack) {
      minStack->push_back(ch);
    } else {
      stacks.push_back({ ch });
    }
  }
  cout << stacks.size() << endl;
  return 0;
}
