#include <iostream>
#include <functional>
#include <deque>

using namespace std;

struct tree {
  int value;
  tree *left;
  tree *right;
};

void tree_insert(tree*, int);
int tree_find(tree*, int);
int tree_parent(tree*, int);
int tree_successor(tree*, int);
int tree_predecessor(tree*, int);
int tree_nearest(tree*, int);
int tree_max(tree*);
int tree_min(tree*);

int main() {
  int n;
  cin >> n;
  tree *bst = new tree { 0 };
  for (int i = 0; i < n; i++) {
    int x;
    cin >> x;
    tree_insert(bst, x);
  }
  int k, m;
  cin >> k >> m;
  function<int(tree*, int)> ops[] {
    tree_find,
    tree_parent,
    tree_successor,
    tree_predecessor,
    tree_nearest,
  };
  for (int i = 0; i < m; i++) {
    int op;
    cin >> op;
    int res = ops[op - 1](bst, k);
    if (res > 0) {
      cout << res;
    } else {
      cout << "NULL";
    }
    cout << endl;
  }
}

void tree_insert(tree *node, int val) {
  if (val < node->value) {
    if (node->left) {
      tree_insert(node->left, val);
    } else {
      node->left = new tree { val };
    }
  } else {
    if (node->right) {
      tree_insert(node->right, val);
    } else {
      node->right = new tree { val };
    }
  }
}

int tree_find(tree *node, int key) {
  if (!node) return 0;
  if (node->value == key) {
    return key;
  } else if (node->value > key) {
    return tree_find(node->left, key);
  } else {
    return tree_find(node->right, key);
  }
}

int tree_parent(tree *node, int key) {
  if (!node) return 0;
  if (node->value == key) {
    return -1;
  } else if (node->value > key) {
    int res = tree_parent(node->left, key);
    if (res == -1) return node->value;
    return res;
  } else {
    int res = tree_parent(node->right, key);
    if (res == -1) return node->value;
    return res;
  }
}

int tree_successor(tree *node, int key) {
  if (!node) return 0;
  if (node->value == key) {
    return tree_min(node->right);
  } else if (node->value > key) {
    int res = tree_successor(node->left, key);
    if (res == -1) return node->value;
    return res;
  } else {
    return tree_successor(node->right, key);
  }
}

int tree_predecessor(tree *node, int key) {
  if (!node) return 0;
  if (node->value == key) {
    return tree_max(node->left);
  } else if (node->value > key) {
    return tree_predecessor(node->left, key);
  } else {
    int res = tree_predecessor(node->right, key);
    if (res == -1) return node->value;
    return res;
  }
}

int tree_nearest(tree *node, int key) {
  if (!node) return -1;
  if (node->value == key) {
    return key;
  } else if (node->value > key) {
    int res = tree_nearest(node->left, key);
    if (res == -1) return node->value;
    if (res < key && node->value - key < key - res) return node->value;
    return res;
  } else {
    int res = tree_nearest(node->right, key);
    if (res == -1) return node->value;
    if (res > key && node->value - key >= key - res) return node->value;
    return res;
  }
}

int tree_max(tree *node) {
  if (!node) return -1;
  int next = tree_max(node->right);
  if (next == -1) return node->value;
  else return next;
}

int tree_min(tree *node) {
  if (!node) return -1;
  int next = tree_min(node->left);
  if (next == -1) return node->value;
  else return next;
}
