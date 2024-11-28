#ifndef TREE_H
#define TREE_H
struct node {
  int data;
  struct node* left;
  struct node* right;
};

struct node* newNode(int data);
struct node* insert(struct node* node, int data);
void printTree(struct node* node);
void printPostOrder(struct node* node);
#endif
