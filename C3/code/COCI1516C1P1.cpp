#include <iostream>
#include <set>
#include <map>
#include <string>

using namespace std;
using namespace std::string_literals;

int main() {
  string data;
  cin >> data;
  map<char, set<int>> deck;
  for (int i = 0; i < data.length(); i += 3) {
    char suit = data[i];
    int rank = (data[i + 1] - '0') * 10 + data[i + 2] - '0';
    if (deck[suit].count(rank)) {
      deck['G'];
      break;
    }
    deck[suit].insert(rank);
  }
  if (deck.count('G')) {
    cout << "GRESKA";
  } else {
    for (char suit : "PKHT"s) {
      cout << 13 - deck[suit].size() << " ";
    }
  }
  cout << endl;
  return 0;
}
