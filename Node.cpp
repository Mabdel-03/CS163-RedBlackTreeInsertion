#include <iostream>
#include <cstring>
#include "Node.h"
using namespace std;

Node::Node(int newVal) {
  val = newVal;
  right = NULL;
  left = NULL;
  parent = NULL;
  color = 1; //colors are 1 and 2, 1 is black 2 is red
}

int Node::getVal() {
  return val;
}

Node* Node::getRight() {
  return right;
}

Node* Node::getLeft() {
  return left;
}

Node* Node::getParent() {
  return parent;
}

void Node::setRight(Node* newRight) {
  right = newRight;
}

void Node::setLeft(Node* newLeft) {
  left = newLeft;
}

void Node::setParent(Node* newParent) {
  parent = newParent;
}
