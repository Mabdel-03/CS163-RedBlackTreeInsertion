#include <iostream>
#include <cstring>
using namespace std;

class Node{

 public:
  Node(int);
  int getVal();
  void setVal(int);
  Node* getRight();
  Node* getLeft();
  Node* getParent();
  void setRight(Node*);
  void setLeft(Node*);
  void setParent(Node*);
  
 private: 
  Node* left;
  Node* right;
  Node* parent;
  int color;
  int val;
  
};
