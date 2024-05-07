#include <iostream>
#include <string>
#include <vector>
#include <tuple>
#include <algorithm>
using namespace std;

const string ranks = "3456789TJQKA2";
const string suits = "CDHS";

typedef pair<char, char> card;

int main() {
  int n;
  cin >> n;
  vector<card> cards;
  for (int i = 0; i < n; i++) {
    char r, s;
    cin >> r >> s;
    cards.emplace_back(r, s);
  }
  sort(
    cards.begin(),
    cards.end(),
    [](card a, card b) {
      int rankDiff = ranks.find(a.first) - ranks.find(b.first);
      if (rankDiff) return rankDiff < 0;
      return suits.find(a.second) < suits.find(b.second);
    }
  );
  for (card c : cards) {
    cout << c.first << " " << c.second << endl;
  }
  return 0;
}
