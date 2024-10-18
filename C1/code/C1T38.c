#include <stdio.h>
#include <stdlib.h>

typedef struct Node {
  int data;
  struct Node* next;
} Node;

Node *head = NULL;

Node* createNode(int data) {
  Node* node = malloc(sizeof(node));
  node->data = data;
  node->next = NULL;
  return node;
}

void insertFirst(int data) {
  Node* node = createNode(data);
  node->next = head;
  head = node;
}
