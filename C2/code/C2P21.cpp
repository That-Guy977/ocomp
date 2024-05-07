#include <iostream>
#include <algorithm>
#include <iterator>
#include <deque>
#include <tuple>
#include <array>
#include <string>

using namespace std;

array<string, 3> types { "fire", "water", "wood" };

struct wizard {
  static wizard none;

  string name;
  int level;
  int type;

  string toString() {
    return name + " " + to_string(level) + " " + types[type];
  }
};

bool bySkill(const wizard &a, const wizard &b);

int main() {
  int r;
  cin >> r;
  for (int ri = 0; ri < r; ri++) {
    int n;
    cin >> n;
    deque<wizard> tourney;
    for (int i = 0; i < n; i++) {
      string name, typeName;
      int level;
      cin >> name >> level >> typeName;
      int type = distance(types.begin(), find(types.begin(), types.end(), typeName));
      tourney.push_back({ name, level, type });
    }
    while (tourney.size() > 2) {
      if (tourney.size() % 2) tourney.push_back({});
      int rounds = tourney.size() / 2;
      for (int i = 0; i < rounds; i++) {
        wizard first = tourney.front();
        tourney.pop_front();
        wizard second = tourney.front();
        tourney.pop_front();
        tourney.push_back(max(first, second, bySkill));
      }
    }
    auto wl = minmax_element(tourney.begin(), tourney.end(), bySkill);
    wizard winner = *get<1>(wl);
    wizard loser = *get<0>(wl);
    cout << winner.toString() << " vs " << loser.toString() << endl;
  }
  return 0;
}

bool bySkill(const wizard &a, const wizard &b) {
  if (a.level != b.level) return a.level < b.level;
  return (a.type + 1) % 3 == b.type;
}
