#include <stdlib.h>
#include <assert.h>
#include "rbtree.h"

RBNode* createRBNode(int key){
  RBNode* newNode = malloc(sizeof(RBNode));
  newNode->parent = NULL;
  newNode->left = NULL;
  newNode->right = NULL;
  newNode->key = key;
  newNode->color = RED;
  return newNode;
}

RBTree* createRBTree(){
  RBTree* t = malloc(sizeof(RBTree));
  t->root = NULL;
  return t;
}

int isRootBlack(RBTree *t){
  if(!t->root) return 1;
  return t->root->color == BLACK;
}

void rbInsert(RBTree *t, RBNode* z){
  RBNode* x = t->root;
  RBNode* y = NULL;

  while(x){
    y = x;
    if(z->key < x->key)
      x = x->left;
    else 
      x = x->right;
  }

  z->parent = y;

  if(!y)
    t->root = z;
  else{
    if(z->key < y->key)
      y->left = z;
    else
      y->right = z;
  }
  //rbInsertFixUp(t, z);
}

void leftRotate(RBTree *t, RBNode *x){
  assert(x != NULL);
  RBNode* y = x->right;
  assert(y != NULL);
  RBNode* B = y->left;
 
  x->right = B;
  if(B) B->parent = x;
  x->parent = y->parent;

  y->left = x;
  y->parent = x->parent;
}

void rightRotate(RBTree *t, RBNode *y){
  assert(y != NULL);
  RBNode* x = y->left;
  assert(x != NULL);
  RBNode* B = x->right;

  y->left = B;
  if(B) B->parent = y;
  y->parent = x->parent;

  x->right = y;
  x->parent = y->parent;
}

void rbInsertFixUp(RBTree *t, RBNode* z){
  while(z->parent->color == RED){
    RBNode* gparent = z->parent->parent;
    if(z->parent == gparent->left){
      RBNode* y = gparent->right;
      if(y->color == RED){
        z->parent->color = BLACK;
        y->color = BLACK;
        gparent->color = RED;
        z = gparent;
      }
      else{
        if(z == z->parent->right){
          z = z->parent;
          leftRotate(t, z);
        }
        z->color = BLACK;
        gparent->color = RED;
        rightRotate(t, z);
      }
    }
  }
}
