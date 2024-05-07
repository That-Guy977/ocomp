#include <iostream>
#include <forward_list>
#include <stack>
#include <cstdio>

using namespace std;

struct node {
  int value;
  struct node *next;
  node(int value, node *next) : value{value}, next{next} {}
};

void list_push(node*, int);
void list_reverse(node*, int, int);
void list_value(node*, int);
void list_print(node*);

int main() {
  node *before_head = new node(0, NULL);
  int m;
  cin >> m;
  for (int i = 0; i < m; i++) {
    int x;
    cin >> x;
    list_push(before_head, x);
  }
  int n;
  cin >> n;
  for (int i = 0; i < n; i++) {
    char op;
    int idx, end;
    cin >> op;
    switch (op) {
      case 'r':
        cin >> idx >> end;
        list_reverse(before_head, idx, end);
        break;
      case 'v':
        cin >> idx;
        list_value(before_head, idx);
        break;
      case 'p':
        list_print(before_head);
        break;
    }
  }
  return 0;
}

void list_push(node *before_head, int val) {
  node *curr = before_head;
  while (curr->next) {
    curr = curr->next;
  }
  curr->next = new node(val, NULL);
}

void list_reverse(node *before_head, int idx, int end) {
  node *curr = before_head;
  stack<node*> rev;
  for (int i = 0; i < idx; i++) {
    curr = curr->next;
  }
  node *pos = curr;
  for (int i = idx; i < end; i++) {
    rev.push(curr->next);
    curr->next = curr->next->next;
  }
  node *tail = curr->next;
  while (rev.size()) {
    pos->next = rev.top();
    pos = pos->next;
    rev.pop();
  }
  pos->next = tail;
}

void list_value(node *before_head, int idx) {
  node *curr = before_head->next;
  int count = idx + 1;
  if (idx < 0) {
    goto fail;
  }
  while (curr && --count) {
    curr = curr->next;
  }
  if (curr) {
    printf("%d: %d\n", idx, curr->value);
  } else {
    fail:
    printf("[%d: invalid index]\n", idx);
  }
}

void list_print(node *before_head) {
  node *curr = before_head;
  while (curr->next) {
    curr = curr->next;
    cout << curr->value << " ";
  }
  cout << endl;
}
