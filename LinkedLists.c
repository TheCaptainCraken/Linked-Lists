#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include "LinkedLists.h"

struct node_s {
    int val;
    struct node_s* next;
};

Node* CreateNode(int val) {
    Node* new_node = (Node*)malloc(sizeof(Node));
    if (new_node == NULL) {
        printf("Allocation error while creating a node.\n");
        return NULL;
    }
    new_node->val = val;
    new_node->next = NULL;
}

int GetListLength(Node* head) {
    Node* current = head;
    int length = 0;
    while (current != NULL) {
        current = current->next;
        length++;
    }
    return length;
}

bool Append(Node** head_pointer, int val) {
    int length = GetListLength(*head_pointer);
    if (length == 0) {
        *head_pointer = CreateNode(val);
        if (*head_pointer == NULL) { return false; }
        else { return true; }
    }
    else {
        Node* new_node = CreateNode(val);
        if (new_node == NULL) { return false; }
        Node* current = *head_pointer;
        while (current->next != NULL) {
            current = current->next;
        }
        current->next = new_node;
        return true;
    }
}

void PrintList(Node* head, const char* separator) {
    Node* current = head;
    while (current->next != NULL) {
        printf("%d%s", current->val, separator);
        current = current->next;
    }
    printf("%d\n", current->val);
}

bool Push(Node** head_pointer, int val) {

    if (*head_pointer == NULL) {
        *head_pointer = CreateNode(val);
        if (*head_pointer == NULL) { return false; }
        else { return true; }
    }

    Node* new_node = CreateNode(val);
    if (new_node == NULL) { return false; }
    new_node->next = *head_pointer;
    *head_pointer = new_node;
    return true;
}
