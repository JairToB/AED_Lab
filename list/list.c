#include<stdlib.h>
#include<assert.h>
#include "list.h"

void push(struct Node** headPtr, int data){
  struct Node* newNode = malloc(sizeof(struct node));
  newNode->data = data;

  newNode->next = *headPtr;

  *headPtr = newNode;
}
int length(struct Node* head){
  int count = 0;
  while(head){
    count++;
    head = head->next;
  }
  return count;
}

struct Node* buildOneTwoThree(){
  struct Node* head = malloc(sizeof(struct Node));
  head->data = 1;
  head->next = malloc(sizeof(struct Node));

  head->next->data = 2;
  head->next->next = malloc(sizeof(struct Node));

  head->next->next->data = 3;
  head->next->next->next = 0;

  return head;
}

int count(struct Node* head, int searchFor){
  int c = 0;
  while(head){
    int data = head->data;
    if(data == searchFor)
      c++;
    head = head->next;
  }
  return c;
}
int getNth(struct Node* head, int index){
  assert(head != NULL);
  assert(index >= 0);
  assert(index < length(head));

  while(head && index){
    index--;
    head = head->next;
  }
  return head->data;
}

void deleteList(struct Node** headPtr){
  while(*headPtr){
    struct Node* tmp = *headPtr;
    *headPtr = (*headPtr)->next;
    free(tmp);
  }
}

int pop(struct Node** headPtr){
  assert(*headPtr);
  int data = (*headPtr)->data;
  struct Node* tmp = *headPtr;
  *headPtr = (*headPtr)->next;
  free(tmp);
  return data;
}

void insertNth(struct Node** headPtr, int idx, int data){
  assert(idx >= 0);
  assert(idx <= length(*headPtr));

  struct Node **current = headPtr;
  while(*current){
    current = &((*current)->next);
  }
}

void sortedInsert(struct Node** headPtr, struct Node * n){
  struct Node* current = *headPtr;
  struct Node* previous = NULL;
  if(current == NULL){
    *headPtr = n;
    n->next = NULL;
  } else {
    while(current->data < n->data){
      previous = current;
      current = current->next;
    }
    if(previous){
      n->next = previous->next;
      previous->next = n;
    }else{
      n->next = *headPtr;
      *headPtr = n;
    }
  }
}
