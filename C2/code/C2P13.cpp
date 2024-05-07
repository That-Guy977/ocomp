#include <iostream>
#include <algorithm>
#include <regex>
#include <map>
#include <string>

using namespace std;

int main() {
  map<string, int> words;
  string text;
  getline(cin, text);
  transform(
    text.begin(),
    text.end(),
    text.begin(), 
    [](unsigned char c){ return tolower(c); }
  );
  string::iterator end = remove_if(
    text.begin(),
    text.end(),
    [](unsigned char c){ return ispunct(c); }
  );
  text.erase(end, text.end());
  regex word_regex("[^ ]+");
  sregex_iterator words_begin(text.begin(), text.end(), word_regex);
  sregex_iterator words_end;
  for (sregex_iterator it = words_begin; it != words_end; ++it) {
    smatch match = *it;
    ++words[match.str()];
  }
  for (const pair<string, int>& word_count : words) {
    string word = word_count.first;
    int count = word_count.second;
    cout << word << " " << count << endl;
  }
  return 0;
}
