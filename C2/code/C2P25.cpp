#include <iostream>
#include <functional>
#include <map>
#include <stack>
#include <string>
#include <cstdio>
#include <cmath>

using namespace std;

map<char, function<double(double, double)>> ops {
  { '+', plus<> {} },
  { '-', minus<> {} },
  { '*', multiplies<> {} },
  { '/', divides<> {} },
  { '^', [](double a, double b) { return pow(a, b); } },
};

struct expr;
struct oper;

union ast_node {
  int literal;
  oper *op;
  ast_node(int literal): literal{literal} {}
  ast_node(oper *op): op{op} {}
};

struct expr {
  int type;
  ast_node *node;
  double value();
  string toString();
};

struct oper {
  char op;
  expr *a, *b;
  double value();
  string toString();
};

double expr::value() {
  if (type == 0) return node->literal;
  else if (type == 1) return node->op->value();
  return 0;
}
string expr::toString() {
  if (type == 0) return to_string(node->literal);
  else if (type == 1) return node->op->toString();
  return "";
}

double oper::value() {
  return ops[op](a->value(), b->value());
}
string oper::toString() {
  return "(" + a->toString() + op + b->toString() + ")";
}

int main() {
  int m;
  cin >> m;
  map<char, int> vars;
  for (int i = 0; i < m; i++) {
    cin >> vars[i + 'A'];
  }
  int n, t;
  cin >> n >> t;
  for (int ni = 0; ni < n; ni++) {
    string raw;
    cin >> raw;
    stack<expr*> ast;
    for (char ch : raw) {
      if (ops.count(ch)) {
        expr *rhs = ast.top();
        ast.pop();
        expr *lhs = ast.top();
        ast.pop();
        oper *op = new oper { ch, lhs, rhs };
        ast.push(new expr { 1, new ast_node(op) });
      } else ast.push(new expr { 0, new ast_node(vars[ch]) });
    }
    expr *root = ast.top();
    if (t == 0) {
      cout << root->toString() <<  endl;
    } else {
      printf("%.2lf\n", root->value());
    }
  }
  return 0;
}
