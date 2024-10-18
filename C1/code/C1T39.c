#include <stdio.h>
#include <stdbool.h>
#define MAXSIZE 1000000

extern bool isFull();
extern bool isEmpty();
extern int peek();

int items[MAXSIZE];
int firstGreaterDay[MAXSIZE];
int top = -1; 

void push(int data) {
  if(!isFull()) {
    items[++top] = data;
  } else {
    printf("Stack is full.\n");
  }
}

void pop() {
  if(!isEmpty()) {
    top--;
  } else {
    printf("Stack is empty.\n");
  }
}

void find_firstGreaterDay(int n, int arr[]) {
  for (int i = n - 1; i >= 0; i--) {
    while (!isEmpty() && arr[i] >= arr[peek()]) pop();
    if (!isEmpty()) {
      firstGreaterDay[i] = peek() + 1;
    } else {
      firstGreaterDay[i] = -1;
    }
    push(i);
  }
  for (int i = 0; i < n; i++) {
    if (i) printf(" ");
    printf("%d", firstGreaterDay[i]);
  }
  printf("\n");
}
