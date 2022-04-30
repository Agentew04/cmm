#include <stdlib.h>
#include <stdio.h>
#include "list.h"

void printList(LIST *list){
    struct Node *current = list->head;

    while (current != NULL){
        printf("%d\n", current->value);
        current = current->next;
    }   
}

void appendToList(LIST *list, int value){
    struct Node* current = list->head;
    struct Node* newNode = createNode(value, NULL);

    // if empty list
    if(current == NULL){
        list->head = newNode;
        list->tail = newNode;
        list->size++;
        return;
    }

    // get to last node
    while(current->next!=NULL) current = current->next;

    // here current is the last
    current->next = newNode;
}

struct Node* createNode(int value, struct Node* next){
    struct Node *node = malloc(sizeof *node);
    node->value = value;
    node->next = next;
    return node;
}

void freeList(LIST *list){
    struct Node* temp;
    while(list->head != NULL){
        temp = list->head;
        list->head = list->head->next;
        free(temp);
    }
    free(list);
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

void removeValueFromList(struct Node* head, int value){
    struct Node* current = head;
    struct Node* previous = NULL;

    while (current != NULL)
    {
        if(current->value == value){
            if(previous == NULL){
                // if the value is the first element
                head = current->next;
            }else{
                previous->next = current->next;
            }
            free(current);
            return;
        }else{
            previous = current;
            current = current->next;
        }
    }
}

LIST* createList(int* values, int size){
    // check if new list should be empty
    LIST* list = malloc(sizeof *list);
    list->size = size;
    if(size == 0 || values == NULL){
        list->head = NULL;
        list->tail = NULL;
    }else{
        list->head = createNode(values[0], NULL);
        list->tail = list->head;
    }

    // if empty the loop will not activate
    for(int i=1; i<size; i++){
        appendToList(list, values[i]);
        list->tail = list->tail->next;
    }
    return list;
}

int main(){
    int values[] = {1,2,3,4,5,6,7,8,9,10};

    //LIST* list = createList(&values[0], (sizeof values)/sizeof(int));
    LIST* list = createList(NULL, 0);

    appendToList(list, 11);
    printList(list);

    freeList(list);
}