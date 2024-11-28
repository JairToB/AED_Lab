#include<stdlib.h>
#include<stdio.h>
#include "tree.h"

struct node* newNode(int data){
  struct node* node = malloc(sizeof(struct node));
  node->data = data;
  node->left = NULL;
  node->right = NULL;
  return node;
}

struct node* insert(struct node* node, int data){
  if(!node)
    return newNode(data);
  if(data < node->data)
    node->left = insert(node->left, data);
  else
    node->right = insert(node->right, data);
  return node;
}

void printTree(struct node* node){
  if(!node) return;
  printTree(node->left);
  printf("%d ", node->data);
  printTree(node->right);
}

void printPostOrder(struct node* node){
  if(!node) return;
  printPostOrder(node->left);
  printPostOrder(node->right);
  printf("%d ", node->data);
}
int hasPathSum(struct node* node, int sum){
  if(node == NULL)
    return (sum == 0);
  return hasPathSum(node->left, sum - node->data) ||
         hasPathSum(node->right, sum - node->data);
}
void printArray(int path[], int pathLen){
  for(int i = 0; i < pathLen; i++)
    printf("%d ", path[i]);
  printf("\n");
}
void printPathsRecur(struct node* node, int path[], int pathLen){
  if(node == NULL)
    return;
  path[pathLen] = node->data;
  pathLen++;
  if(node->left == NULL && node->right == NULL)
    printArray(path, pathLen);
  else{
    printPathsRecur(node->left, path, pathLen);
    printPathsRecur(node->right, path, pathLen);
  }
}
void printPaths(struct node* node){
  int size = size(node);
  int *path = malloc(sizeof(int) * size);
  printPathsRecur(node, path, 0);
}
