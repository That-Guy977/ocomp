#include <iostream>
#include <map>
#include <string>
#include <cctype>

using namespace std;

map<char, char> alphamap = {
  { 'A', '2' },
  { 'B', '2' },
  { 'C', '2' },
  { 'D', '3' },
  { 'E', '3' },
  { 'F', '3' },
  { 'G', '4' },
  { 'H', '4' },
  { 'I', '4' },
  { 'J', '5' },
  { 'K', '5' },
  { 'L', '5' },
  { 'M', '6' },
  { 'N', '6' },
  { 'O', '6' },
  { 'P', '7' },
  { 'R', '7' },
  { 'S', '7' },
  { 'T', '8' },
  { 'U', '8' },
  { 'V', '8' },
  { 'W', '9' },
  { 'X', '9' },
  { 'Y', '9' },
};

string normalize(string);

int main() {
  int n;
  cin >> n;
  for (int ni = 0; ni < n; ni++) {
    if (ni) cout << endl;
    int k;
    cin >> k;
    map<string, int> phonebook;
    for (int i = 0; i < k; i++) {
      string raw;
      cin >> raw;
      phonebook[normalize(raw)]++;
    }
    bool repeat = false;
    for (const pair<string, int> &entry : phonebook) {
      if (entry.second > 1) {
        cout << entry.first << " " << entry.second << endl;
        repeat = true;
      }
    }
    if (!repeat) {
      cout << "No" << endl;
    }
  }
  return 0;
}

string normalize(string raw) {
  string normal;
  for (char ch : raw) {
    if (isdigit(ch)) normal += ch;
    if (isalpha(ch)) normal += alphamap[ch];
    if (normal.length() == 3) normal += '-';
  }
  return normal;
}
