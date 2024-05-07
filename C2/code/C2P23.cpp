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
void tree_pre_order(tree*);
void tree_in_order(tree*);
void tree_post_order(tree*);
void tree_level_order(tree*);
void tree_leaves(tree*);

int main() {
  int n;
  cin >> n;
  tree *bst = new tree { 0 };
  for (int i = 0; i < n; i++) {
    int x;
    cin >> x;
    tree_insert(bst, x);
  }
  int m;
  cin >> m;
  function<void(tree*)> ops[] {
    tree_pre_order,
    tree_in_order,
    tree_post_order,
    tree_level_order,
    tree_leaves,
  };
  for (int i = 0; i < m; i++) {
    int op;
    cin >> op;
    ops[op - 1](bst);
  }
}

void tree_insert(tree *node, int val) {
  if (val > node->value) {
    if (node->right) {
      tree_insert(node->right, val);
    } else {
      node->right = new tree { val };
    }
  } else {
    if (node->left) {
      tree_insert(node->left, val);
    } else {
      node->left = new tree { val };
    }
  }
}

void tree_pre_order(tree *node) {
  if (!node) return;
  bool root = !node->value;
  if (!root) cout << node->value << " ";
  tree_pre_order(node->left);
  tree_pre_order(node->right);
  if (root) cout << endl;
}

void tree_in_order(tree *node) {
  if (!node) return;
  bool root = !node->value;
  tree_in_order(node->left);
  if (!root) cout << node->value << " ";
  tree_in_order(node->right);
  if (root) cout << endl;
}

void tree_post_order(tree *node) {
  if (!node) return;
  bool root = !node->value;
  tree_post_order(node->left);
  tree_post_order(node->right);
  if (!root) cout << node->value << " ";
  if (root) cout << endl;
}

void tree_level_order(tree *root) {
  deque<tree*> curr { root->right };
  deque<tree*> next;
  for (int level = 0; curr.size(); level++) {
    cout << level << ":";
    for (tree *node : curr) {
      cout << node->value << " ";
      if (node->left) next.push_back(node->left);
      if (node->right) next.push_back(node->right);
    }
    cout << endl;
    curr = next;
    next.clear();
  }
}

void tree_leaves(tree *node) {
  if (!node) return;
  bool root = !node->value;
  tree_leaves(node->left);
  if (!node->left && !node->right) cout << node->value << " ";
  tree_leaves(node->right);
  if (root) cout << endl;
}
