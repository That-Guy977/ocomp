#include <iostream>
#include <set>
#include <map>
#include <tuple>

using namespace std;

int main() {
  int n;
  cin >> n;
  map<set<int>, int> minors;
  for (int i = 0; i < n; i++) {
    set<int> course;
    for (int j = 0; j < 5; j++) {
      int minor;
      cin >> minor;
      course.insert(minor);
    }
    minors[course]++;
  }
  int maxPop = 0;
  int maxPopCount = 0;
  for (const pair<set<int>, int> &minor : minors) {
    if (minor.second > maxPop) {
      maxPop = minor.second;
      maxPopCount = 1;
    } else if (minor.second == maxPop) {
      maxPopCount++;
    }
  }
  cout << maxPop * maxPopCount << endl;
  return 0;
}
