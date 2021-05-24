//Code Written By Mahmoud Abdelmoneum on 5/23/2021
//Code Written To be a Red Black Tree implementation that takes number input
// either in the form of file input or console input and put into a RB Tree
// This Code is not yet complete

#include <iostream>
#include <fstream>
#include <cstring>
#include <cstdlib>
#include "Node.h"
using namespace std;

void rotateLeft(Node*&, Node*&);
void rotateRight(Node*&, Node*&);
void insert(Node*&, int);
void addNode(Node*&, Node*);
// not done yet, but will have a void traverse(Node*, int);


int main() {

  //set head
  Node* head = NULL;
  char type;
  char input[999];

  //prompt user for type
  cout << "Enter 1 for file input, enter 2 for manual input" << endl;

  cin >> type;
  //file input
  if(type == '1') {
    //got tutorial for this portion from cplusplus.com/doc/tutorial/files/
    cout << "Please enter the file name" << endl;
    char fileInput[999];
    cin.getline(fileInput, sizeof(fileInput));
    ifstream fileStream;
    fileStream.open(fileInput);
    if(fileStream) {
      fileStream.getline(input, sizeof(input));
    }
    else { //file doesn't exist
      cout << "This file cannot be found" << endl;
    }

  }

  else if(type == '2') {
    cout << "Please enter the number set, dividing each number by a space" << endl;
    cin.getline(input, 999);
  }
  char* list = strtok(input, " "); //strtok splits up input by spaces
  while(list) {
    insert(head, atoi(list));
    list = strtok(NULL, " ");
  }
  while(true) {
    cout << "Enter ADD to add to the RB tree, PRINT to print it, SEARCH to search for any value, and QUIT to exit the program" << endl;
    cin.getline(input, sizeof(input));
    for(int i = 0; i<sizeof(input); i++) {
      input[i] = toupper(input[i]);
    }
    if(strcmp(input, "ADD") == 0) { //add a new node
      int val;
      cout << "Enter the value that you would like to add" << endl;
      cin >> val;
      insert(head, val);
    }
    else if(strcmp(input, "PRINT") == 0) { //print out/display the RB Tree
      //this portion has not been coded yet
      //traverse(head, 0);
    }
    else if(strcmp(input, "QUIT") == 0) {
      return 0;
    }
    
  }
}

void addNode(Node* &head, Node* n) {
   if(head == NULL) { //add head if current head is NULL
     head = n;
     return;
   }

   if(head->getVal() < n->getVal()) { //if the input is LARGER than the head
     if(head->getRight() == NULL) { //if at base of tree, add new node right
       head->setRight(n);
       head->getRight()->setParent(head);
       return;
     }
     else { //otherwise, traverse right
	 Node* right = head->getRight();
       addNode(right, n);
     }
   }
   else { //if the input is SMALLER than the head
     if(head->getLeft() == NULL) { //if left of head is empty
       head->setLeft(n);
       head->getLeft()->setParent(head);
       return;
     }
     else { //if not, we will traverse further down the left side
       Node* left = head->getLeft();
       addNode(left, n);
     }
   }
}

void insert(Node* &head, int val) {
  Node* n = new Node(val);
  addNode(head, n); 
}
