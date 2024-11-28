#include<stdio.h>
#include "avl.h"
int main(int argc, char* argv[]){
  struct AVL* root = 0;
  printf("%d\n", balanceFactor(root));

  root = insertBST(root, 4);
  printf("%d\n", balanceFactor(root));

  root = insertBST(root, 2);
  printf("%d\n", balanceFactor(root));

  root = insertBST(root, 1);
  printf("%d\n", balanceFactor(root));

  root = insertBST(root, 3);
  printf("%d\n", balanceFactor(root));

  root = insertBST(root, 5);
  printf("%d\n", balanceFactor(root));
}
