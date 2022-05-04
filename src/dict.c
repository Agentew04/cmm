#include <stdio.h>
#include <stdlib.h>
#include "dict.h"

static struct Node* createNode(int key, int value, struct Node* next){
    struct Node* node = (struct Node*) malloc(sizeof(struct Node));
    node->value = value;
    node->next = next;
    node->key = key;
    return node;
}

void appendToDict(DICT* list, int key, int value){
    struct Node* node = createNode(key, value, NULL);
    if(list->head == NULL){
        list->head = node;
        list->tail = node;
    }else{
        list->tail->next = node;
        list->tail = node;
    }
    list->size++;
}

DICT* createDict(int* keys, int* values){
    int keysSize = sizeof(*keys) / sizeof(int);
    int valuesSize = sizeof(*values) / sizeof(int);

    if(keysSize != valuesSize){
        //printf("Error: The size of the arrays are not equal");
        return NULL;
    }

    DICT* dict = (DICT*) malloc(sizeof(DICT));
    dict->size = 0;
    dict->head = NULL;
    dict->tail = NULL;

    for(int i = 0; i < keysSize; i++){
        appendToDict(dict, keys[i], values[i]);
    }

    return dict;
}