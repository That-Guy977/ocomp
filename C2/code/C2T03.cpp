#include <iostream>
#include <vector>

using namespace std;

typedef vector<int> tower;

void step(int, tower[], int, int, int, int);
void move(int, tower[], int, int);
void print(int, tower[]);

int main() {
  int n;
  cin >> n;
  tower towers[3];
  for (int i = 0; i < n; i++) {
    towers[0].insert(towers[0].begin(), i);
  }
  print(n, towers);
  step(n, towers, n - 1, 0, 2, 1);
  return 0;
}

void step(int n, tower towers[], int x, int src, int dst, int aux) {
  if (x) {
    step(n, towers, x - 1, src, aux, dst);
    move(n, towers, src, dst);
    step(n, towers, x - 1, aux, dst, src);
  } else {
    move(n, towers, src, dst);
  }
}

void move(int n, tower towers[], int src, int dst) {
  int x = towers[src].back();
  towers[src].pop_back();
  towers[dst].push_back(x);
  print(n, towers);
}

void print(int n, tower towers[]) {
  int margin = n - 1;
  vector<string> repr[3];
  for (int i = 0; i < 3; i++) {
    for (int j = 0; j < n; j++) {
      string line;
      if (j < towers[i].size()) {
        int edge = towers[i][j];
        string gap = string(margin - edge, '.');
        line = gap + string(2 * edge + 1, '=') + gap;
      } else {
        string gap = string(margin, '.');
        line = gap + '|' + gap;
      }
      repr[i].push_back(line);
    }
  }
  for (int i = n - 1; i >= 0; i--) {
    for (int j = 0; j < 3; j++) {
      if (j) cout << '.';
      cout << repr[j][i];
    }
    cout << endl;
  }
  cout << string(margin * 6 + 5, '-') << endl;
}
