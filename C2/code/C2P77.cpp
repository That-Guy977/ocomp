#include <iostream>
#include <algorithm>
#include <vector>
#include <queue>
#include <cmath>

using namespace std;

struct BinTree {
  int value;
  BinTree* left;
  BinTree* right;
  bool empty() {
    return value == -1;
  }
  bool is_leaf() {
    return left->empty() && right->empty();
  }
};

BinTree null { -1 };

void tree_link(BinTree*[], int, int);
int tree_max(BinTree*);
void tree_in_order(BinTree*);
void tree_pre_order(BinTree*);
void tree_post_order(BinTree*);
int tree_leaf_count(BinTree*);
int tree_search_parent(BinTree*, int);
int tree_search_sibling(BinTree*, int);
int bin_perm(int);

int main() {
  int h;
  cin >> h;
  int nodeCount = bin_perm(h);
  BinTree *nodes[nodeCount];
  for (int i = 0; i < nodeCount; i++) {
    int x;
    cin >> x;
    nodes[i] = new BinTree { x };
  }
  tree_link(nodes, bin_perm(h - 1), 0);
  BinTree *root = nodes[0];
  int n;
  cin >> n;
  for (int i = 0; i < n; i++) {
    char op;
    cin >> op;
    int key, res;
    switch (op) {
      case 'm':
        cout << tree_max(root) << endl;
        break;
      case 'i':
        tree_in_order(root);
        cout << endl;
        break;
      case 'a':
        tree_pre_order(root);
        cout << endl;
        break;
      case 'b':
        tree_post_order(root);
        cout << endl;
        break;
      case 'l':
        cout << tree_leaf_count(root) << endl;
        break;
      case 'p':
        cin >> key;
        res = tree_search_parent(root, key);
        cout << (res < 0 ? -1 : res) << endl;
        break;
      case 's':
        cin >> key;
        res = tree_search_sibling(root, key);
        cout << (res < 0 ? -1 : res) << endl;
        break;
    }
  }
  return 0;
}

void tree_link(BinTree *source[], int n, int idx) {
  BinTree *parent = source[idx];
  if (idx < n) {
    int leftIdx = 2 * idx + 1;
    BinTree *leftNode = source[leftIdx];
    parent->left = leftNode;
    if (leftNode->value != -1) {
      tree_link(source, n, leftIdx);
    }
    int rightIdx = 2 * idx + 2;
    BinTree *rightNode = source[rightIdx];
    parent->right = rightNode;
    if (rightNode->value != -1) {
      tree_link(source, n, rightIdx);
    }
  } else {
    parent->left = &null;
    parent->right = &null;
  }
}

int tree_max(BinTree *node) {
  if (node->empty()) return -1;
  return max({ node->value, tree_max(node->left), tree_max(node->right) });
}

void tree_in_order(BinTree *node) {
  if (!node->empty() && !node->is_leaf()) tree_in_order(node->left);
  cout << node->value << " ";
  if (!node->empty() && !node->is_leaf()) tree_in_order(node->right);
}

void tree_pre_order(BinTree *node) {
  cout << node->value << " ";
  if (!node->empty() && !node->is_leaf()) tree_pre_order(node->left);
  if (!node->empty() && !node->is_leaf()) tree_pre_order(node->right);
}

void tree_post_order(BinTree *node) {
  if (!node->empty() && !node->is_leaf()) tree_post_order(node->left);
  if (!node->empty() && !node->is_leaf()) tree_post_order(node->right);
  cout << node->value << " ";
}

int tree_leaf_count(BinTree *node) {
  if (node->empty()) return 0;
  if (node->is_leaf()) return 1;
  return tree_leaf_count(node->left) + tree_leaf_count(node->right);
}

int tree_search_parent(BinTree *node, int key) {
  if (!node->empty()) {
    if (node->value == key) {
      return -2;
    }
    int search_left = tree_search_parent(node->left, key);
    if (search_left == -2) {
      return node->value;
    } else if (search_left != -1) {
      return search_left;
    }
    int search_right = tree_search_parent(node->right, key);
    if (search_right == -2) {
      return node->value;
    } else if (search_right != -1) {
      return search_right;
    }
  }
  return -1;
}

int tree_search_sibling(BinTree *node, int key) {
  if (!node->empty()) {
    if (node->value == key) {
      return -2;
    }
    int search_left = tree_search_sibling(node->left, key);
    if (search_left == -2) {
      return node->right->value;
    } else if (search_left != -1) {
      return search_left;
    }
    int search_right = tree_search_sibling(node->right, key);
    if (search_right == -2) {
      return node->left->value;
    } else if (search_right != -1) {
      return search_right;
    }
  }
  return -1;
}

int bin_perm(int x) {
  return pow(2, x) - 1;
}

/**
 *      88
 *     /  \
 *   -1    32
 *       /    \
 *      7     26
 *     / \   /  \
 *   -1  46 44  -1
 */
