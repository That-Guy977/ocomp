#include <iostream>
#include <string>

using namespace std;

struct Cage {
  int no;
  int capacity;
  string name;
  Cage *next;
};

Cage *first = NULL;

Cage *createCage(int no, int capacity, const string &name) {
  Cage *newCage = new Cage;
  newCage->no = no;
  newCage->capacity = capacity;
  newCage->name = name;
  newCage->next = NULL;
  return newCage;
}

void showCagesWithCapacityGreaterThanK(int k) {
  Cage *curr = first;
  bool f = 1;
  while (curr) {
    if (curr->capacity > k) {
      if (f) f = 0;
      else cout << " ";
      cout << curr->no;
    }
    curr = curr->next;
  }
  cout << endl;
}

void movetofirst(int no) {
  if (first->no == no) return;
  Cage *curr = first;
  while (curr->next->no != no) {
    curr = curr->next;
  }
  Cage *next = curr->next->next;
  curr->next->next = first;
  first = curr->next;
  curr->next = next;
}

void insertLast(int no, int capacity, const string &name) {
  Cage *newCage = createCage(no, capacity, name);
  if (first) {
    Cage *curr = first;
    while (curr->next) {
      curr = curr->next;
    }
    curr->next = newCage;
  } else {
    first = newCage;
  }
}

void shuffle(int no) {
  if (first->no == no) return;
  Cage *curr = first;
  while (curr->next->no != no) {
    curr = curr->next;
  }
  Cage *tail = curr;
  while (curr->next) {
    curr = curr->next;
  }
  curr->next = first;
  first = tail->next;
  tail->next = NULL;
}

void deleteCage(const string &s) {
  if (first->name == s) {
    Cage *head = first;
    first = first->next;
    delete head;
  } else {
    Cage *curr = first;
    while (curr->next->name != s) {
      curr = curr->next;
    }
    Cage *node = curr->next;
    curr->next = node->next;
    delete node;
  }
}
