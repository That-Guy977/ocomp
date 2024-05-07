#include <iostream>
#include <forward_list>
#include <cstdio>

using namespace std;

struct node {
  int value;
  struct node *next;
  node(int value, node *next) : value{value}, next{next} {}
};

node *list_insert(node*, int, int);
node *list_delete(node*, int);
void list_value(node*, int);
void list_print(node*);

int main() {
  node *before_head = new node(0, NULL);
  int n;
  cin >> n;
  for (int i = 0; i < n; i++) {
    char op;
    int idx, val;
    cin >> op;
    switch (op) {
      case 'i':
        cin >> idx >> val;
        before_head = list_insert(before_head, val, idx);
        break;
      case 'd':
        cin >> idx;
        before_head = list_delete(before_head, idx);
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

node *list_insert(node *before_head, int val, int idx) {
  node *curr = before_head;
  int count = idx + 1;
  if (idx < 0) {
    goto fail;
  }
  while (curr && --count) {
    curr = curr->next;
  }
  if (curr) {
    curr->next = new node(val, curr->next);
  } else {
    fail:
    printf("[%d: %d not inserted]\n", idx, val);
  }
  return before_head;
}

node *list_delete(node *before_head, int idx) {
  node *curr = before_head;
  int count = idx + 1;
  if (idx < 0) {
    goto fail;
  }
  while (curr->next && --count) {
    curr = curr->next;
  }
  if (curr->next) {
    node *del = curr->next;
    curr->next = del->next;
    printf("[%d: %d deleted]\n", idx, del->value);
    delete del;
  } else {
    fail:
    printf("[%d: not deleted]\n", idx);
  }
  return before_head;
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
