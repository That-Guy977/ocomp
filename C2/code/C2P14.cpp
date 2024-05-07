#include <iostream>
#include <vector>

using namespace std;

void hash_insert(vector<vector<int>>&, int);

int main() {
  vector<vector<int>> hash;
  int m, n;
  cin >> m >> n;
  for (int i = 0; i < m; i++) {
    hash.emplace_back();
  }
  int count = 0;
  for (int i = 0; i < n; i++) {
    int x;
    cin >> x;
    hash_insert(hash, x);
    if (++count > hash.size() / 2) {
      vector<vector<int>> values = hash;
      hash = {};
      m *= 2;
      for (int i = 0; i < m; i++) {
        hash.emplace_back();
      }
      for (vector<int>& bucket : values) {
        for (int& value : bucket) {
          hash_insert(hash, value);
        }
      }
    }
  }
  for (vector<int>& bucket : hash) {
    if (bucket.size()) {
      for (int& value : bucket) {
        cout << value << " ";
      }
    } else {
      cout << "empty";
    }
    cout << endl;
  }
  return 0;
}

void hash_insert(vector<vector<int>>& hash, int value) {
  hash[value % hash.size()].push_back(value);
}
