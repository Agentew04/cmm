#include <stdlib.h>
#include <stdio.h>
#include "list.h"

void printList(struct Node *head){
    struct Node *current = head;

    while (current != NULL){
        printf("%d\n", current->value);
        current = current->next;
    }   
}

void appendToList(struct Node* node, int value){
    struct Node* current = node;

    // get to last node
    while(current->next!=NULL) current = current->next;

    // here current is the last
    struct Node* newNode = createNode(value, NULL);
    current->next = newNode;
}

struct Node* createNode(int value, struct Node* next){
    struct Node *node = malloc(sizeof *node);
    node->value = value;
    node->next = next;
    return node;
}

void freeList(struct Node* head){
    struct Node* temp;
    while(head != NULL){
        temp = head;
        head = head->next;
        free(temp);
    }
}

int getFirstIndex(struct Node* head, int value){
    struct Node* current = head;
    int index = 0;

    while (current != NULL)
    {
        if(current->value == value){
            return index;
        }else{
            index+=1;
            current = current->next;
        }
    }
    return -1;
}

int main(){
    struct Node* nodetail = createNode(17, NULL);
    struct Node* nodemiddle = createNode(16, nodetail);
    struct Node* nodehead = createNode(15, nodemiddle);
    appendToList(nodehead, 18);
    printList(nodehead);

    int index = getFirstIndex(nodehead, 17);
    printf("%d\n", index);

    freeList(nodehead);
}