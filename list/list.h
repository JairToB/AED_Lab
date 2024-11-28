#ifndef LIST_H
#define LIST_H
struct Node {
  int data;
  struct Node* next;
};

int length(struct Node* head);
struct Node* buildOneTwoThree();
int count(struct Node* head, int searchFor);
int getNth(struct Node* head, int index);
void deleteList(struct Node** headPtr);
int pop(struct Node** headPtr);
void insertNth(struct Node** headPtr, int idx, int data);
#endif
