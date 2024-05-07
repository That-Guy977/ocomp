#include <iostream>
#include <vector>
#include <string>

using namespace std;

struct sensor {
  int f;
  string name; 
};

struct reading {
  long t;
  string name; 
};

int main() {
  int n, k;
  cin >> n >> k;
  vector<sensor> sensors;
  vector<reading> readings;
  for (int i = 0; i < n; i++) {
    string name;
    int f;
    cin >> name >> f;
    sensors.push_back({ f, name });
  }
  long t = 1;
  while (readings.size() < k) {
    for (sensor &sensor : sensors) {
      if (t % sensor.f == 0) readings.push_back({ t, sensor.name });
    }
    t++;
  }
  for (int i = 0; i < k; i++) {
    cout << readings[i].t << " " << readings[i].name << endl;
  }
  return 0;
}
