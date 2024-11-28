#include "tree.h"
int main(int argc, char* argv[]){
  struct node *root = 0;
  root = insert(root, 4);
  root = insert(root, 5);
  root = insert(root, 2);
  root = insert(root, 1);
  root = insert(root, 3);
  printPostOrder(root);
}
