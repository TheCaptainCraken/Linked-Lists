#pragma once
#include <stdbool.h>

typedef struct node_s Node;

/* creates a new node on th head and returns a pointer to it */
Node* CreateNode(int val);
/* appends a new node at the end of the list */
bool Append(Node** head_pointer, int val);
/* appends a new node at the start of the list */
bool Push(Node** head_pointer, int val);
/* deletes the first element of the list and returns its value */
int Pop(Node** head_pointer);
/* deletes the last element of the list and returns its value */
int BackPop(Node** head_pointer);
/* creates a string from the list */
char* ListToString(Node* head);
/* creates an array on the heap from the list */
int* ListToArray(Node* head, int* length);
/* finds the element corresponding to an index (returns -1 if the index is invalid) */
int FindFromIndex(Node* head, int index);
/* deletes an element based on its index in the list */
bool DeleteFromIndex(Node** head, int index);
/* deletes the list */
void DeleteList(Node** head);
/* returns the length of a list */
int GetListLength(Node* head);