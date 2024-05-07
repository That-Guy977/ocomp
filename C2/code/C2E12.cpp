#include <iostream>
#include <map>
#include <set>
#include <tuple>

using namespace std;

int main() {
  int C, N;
  cin >> C >> N;
  set<tuple<int, int, int, int>> submissions;
  for (int i = 0; i < N; i++) {
    int c, d, t, r;
    cin >> c >> d >> t >> r;
    submissions.emplace(t, c, d, r);
  }
  map<int, map<int, pair<bool, int>>> teams;
  for (int i = 1; i <= C; i++) teams[i];
  for (const tuple<int, int, int, int> &submission : submissions) {
    int c, d, t, r;
    tie(t, c, d, r) = submission;
    if (r) {
      teams[c][d].first = true;
      teams[c][d].second += t;
    } else {
      teams[c][d].second += 1200;
    }
  }
  set<tuple<int, int, int>> ranking;
  for (const pair<int, map<int, pair<bool, int>>> &team: teams) {
    int d = 0;
    int t = 0;
    for (const pair<int, pair<bool, int>> &dish : team.second) {
      if (dish.second.first) {
        d++;
        t += dish.second.second;
      }
    }
    ranking.emplace(-d, t, team.first);
  }
  for (const tuple<int, int, int> &team : ranking) {
    cout << get<2>(team) << " ";
  }
  cout << endl;
  return 0;
}
