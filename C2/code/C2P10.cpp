#include <iostream>
#include <forward_list>

using namespace std;

struct node {
  int value;
  struct node *next;
  node(int value, node *next) : value{value}, next{next} {}
};

node *list_insert(node*, int);
node *list_delete(node*, int);
void list_print(node*);

int main() {
  node *head = NULL;
  int n;
  cin >> n;
  for (int i = 0; i < n; i++) {
    char op;
    int val;
    cin >> op;
    switch (op) {
      case 'i':
        cin >> val;
        head = list_insert(head, val);
        break;
      case 'd':
        cin >> val;
        head = list_delete(head, val);
        break;
      case 'p':
        list_print(head);
        break;
    }
  }
  return 0;
}

node *list_insert(node *head, int val) {
  node *before_head = new node(0, head);
  node *curr = before_head;
  while (curr->next && curr->next->value < val) {
    curr = curr->next;
  }
  curr->next = new node(val, curr->next);
  head = before_head->next;
  delete before_head;
  return head;
}

node *list_delete(node *head, int val) {
  node *before_head = new node(0, head);
  node *curr = before_head;
  while (curr->next && curr->next->value != val) {
    curr = curr->next;
  }
  if (curr->next) {
    found:
    node *next = curr->next->next;
    delete curr->next;
    curr->next = next;
    cout << val << " [deleted]" << endl;
  } else {
    cout << val << " [not deleted]" << endl;
  }
  head = before_head->next;
  delete before_head;
  return head;
}

void list_print(node *head) {
  while (head) {
    cout << head->value << " ";
    head = head->next;
  }
  cout << endl;
}
