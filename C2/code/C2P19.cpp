#include <iostream>
#include <algorithm>
#include <iterator>
#include <vector>
#include <array>
#include <string>
#include <cstdio>

using namespace std;

struct event {
  int date;
  string id;
};

array<string, 12> months { "Jan", "Feb", "Mar", "Apr", "May", "Jun", "Jul", "Aug", "Sep", "Oct", "Nov", "Dec" };
const event none {};

event binarySearch(vector<event>&, int, int, int, int);
int toDate(int, string, int);
string toDateString(int);

int main() {
  int n;
  cin >> n;
  vector<event> events;
  for (int i = 0; i < n; i++) {
    int d, y;
    string b, id;
    cin >> d >> b >> y >> id;
    events.push_back({ toDate(d, b, y), id });
  }
  int m;
  cin >> m;
  for (int i = 0; i < m; i++) {
    int t, d, y;
    string b;
    cin >> t >> d >> b >> y;
    int date = toDate(d, b, y);
    event event = binarySearch(events, date, 0, n - 1, t);
    cout << "key: " + toDateString(date);
    if (event.date) {
      cout << " found " << event.id;
    } else {
      cout << " not found";
    }
    cout << endl;
  }
  return 0;
}

event binarySearch(vector<event> &events, int date, int start, int end, int t) {
  while (start <= end) {
    int mid = (start + end) / 2;
    int midDate = events[mid].date;
    if (t) {
      cout << "[" << mid << "]: " << toDateString(midDate) << endl;
    }
    if (midDate == date) {
      return events[mid];
    } else if (midDate > date) {
      end = mid - 1;
    } else {
      start = mid + 1;
    }
  }
  return none;
}

int toDate(int d, string b, int y) {
  int m = distance(months.begin(), find(months.begin(), months.end(), b));
  return y * 10000 + m * 100 + d;
}

string toDateString(int date) {
  int d = date % 100;
  string m = months[date % 10000 / 100];
  int y = date / 10000;
  char datestring[12];
  sprintf(datestring, "%d/%s/%d", d, m.c_str(), y);
  return datestring;
}
