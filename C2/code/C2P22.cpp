#include <iostream>
#define NONE 0xFFFFF
#define VALUE_MASK 0xFFFFFFFFFFF
#define NEXT_SHIFT 44

using namespace std;

long node_get_value(unsigned long[], int);
int node_get_next(unsigned long[], int);
void node_set_value(unsigned long[], int, long);
void node_set_next(unsigned long[], int, int);

struct list {
  int head = NONE;
  int tail = NONE;
  void push(unsigned long nodes[], int node) {
    if (head == NONE) {
      head = node;
    } else {
      node_set_next(nodes, tail, node);
    }
    tail = node;
  }
  void shift_to(unsigned long nodes[], list& other) {
    int node = head;
    head = node_get_next(nodes, head);
    node_set_next(nodes, node, NONE);
    other.push(nodes, node);
  }
  void splice(unsigned long nodes[], list& other) {
    int node = other.head;
    if (node != NONE) {
      push(nodes, node);
      tail = other.tail;
      other.head = NONE;
      other.tail = NONE;
    }
  }
};

void print(unsigned long[], list&);
int digit(long, int);
int length(long);

int main() {
  int n, s;
  cin >> n >> s;
  unsigned long nodes[n];
  list ls;
  int maxLen = 0;
  for (int i = 0; i < n; i++) {
    long x;
    cin >> x;
    node_set_value(nodes, i, x);
    node_set_next(nodes, i, NONE);
    ls.push(nodes, i);
    int len = length(x);
    if (len > maxLen) maxLen = len;
  }
  list buckets[10];
  for (int i = 0; i < maxLen; i++) {
    while (ls.head != NONE) {
      ls.shift_to(nodes, buckets[digit(node_get_value(nodes, ls.head), i)]);
    }
    for (list& bucket : buckets) {
      ls.splice(nodes, bucket);
    }
    if (s) print(nodes, ls);
  }
  if (!s) print(nodes, ls);
  return 0;
}

long node_get_value(unsigned long nodes[], int node) {
  return nodes[node] & VALUE_MASK;
}

int node_get_next(unsigned long nodes[], int node) {
  return nodes[node] >> NEXT_SHIFT;
}

void node_set_value(unsigned long nodes[], int node, long value) {
  nodes[node] &= ~VALUE_MASK;
  nodes[node] |= value;
}

void node_set_next(unsigned long nodes[], int node, int next) {
  nodes[node] &= VALUE_MASK;
  nodes[node] |= (long)next << NEXT_SHIFT;
}

void print(unsigned long nodes[], list& ls) {
  int curr = ls.head;
  while (curr != NONE) {
    cout << node_get_value(nodes, curr) << " ";
    curr = node_get_next(nodes, curr);
  }
  cout << endl;
}

int digit(long x, int d) {
  long dv = 1;
  while (d--) {
    dv *= 10;
  }
  return x % (dv * 10) / dv;
}

int length(long x) {
  int len = 0;
  do {
    x /= 10;
    len++;
  } while (x);
  return len;
}
