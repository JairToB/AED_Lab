#include<stdio.h>
#include<stdlib.h>
#include "avl.h"

int max(int a, int b){
  return (a > b) ? a : b;
}

int abs(int a){
  return (a < 0) ? -a : a;
}

struct AVL* newNode(int data){
  struct AVL* node = malloc(sizeof(struct AVL));
  node->data = data;
  node->left = NULL;
  node->right = NULL;
  node->parent = NULL;
  return node;
}

struct AVL* insertBST(struct AVL* node, int data){
  if(!node)
    return newNode(data);
  if(data < node->data){
    node->left = insertBST(node->left, data);
    node->left->parent = node;
  }else{
    node->right = insertBST(node->right, data);
    node->right->parent = node;
  }
  return node;
}
int height(struct AVL* node){
  if(!node) return -1;
  return 1 + max(height(node->left), height(node->right));
}
int balanceFactor(struct AVL* node){
  if(!node) return 0;
  return height(node->right) - height(node->left);
}
int isAVL(struct AVL* node){
  if(!node) return 1;
  return (abs(balanceFactor(node)) <= 1) &&
          isAVL(node->left) &&
          isAVL(node->right);
}
