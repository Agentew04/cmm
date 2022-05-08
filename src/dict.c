#include <stdio.h>
#include <stdlib.h>
#include "dict.h"

#define ARRAY_SIZE(x) ( sizeof(x) / sizeof((x)[0]) )

static struct Node* createNode(char* key, int value, struct Node *next){
    struct Node* node = (struct Node*) malloc(sizeof(struct Node));
    node->next = next;
    int hash = crc32b(key);
    struct KeyValuePair* pair = (struct KeyValuePair*) malloc(sizeof(struct KeyValuePair));
    pair->key = key;
    pair->value = value;
    node->hash = hash;
    node->pair = pair;
    return node;
}

void addToDict(DICT *dict, char *key, int value){
    struct Node* node = createNode(key, value, NULL);
    if(dict->head == NULL){
        dict->head = node;
        dict->tail = node;
    }else{
        dict->tail->next = node;
        dict->tail = node;
    }
    dict->size++;
}

void removeFromDict(DICT *dict, int key){
    struct Node* node = dict->head;
    unsigned int hash = crc32b(key);
    struct Node* prev = NULL;
    while(node != NULL){
        if(node->hash==hash){
            if(prev == NULL){
                // if its the first node
                dict->head = node->next;
            }else{
                prev->next = node->next;
            }   
            free(node->pair);
            free(node);
            dict->size--;
            return;
        }
        prev = node;
        node = node->next;
    }
}

int getValueFromDict(DICT *dict, int key){

    
    unsigned int hash = crc32b(key);
    struct Node* node = dict->head;
    while(node != NULL){
        if(node->hash == hash){
            return node->pair->value;
        }
        node = node->next;
    }
    return -1;
}

void editValueInDict(DICT *dict, int key, int value){
    unsigned int hash = crc32b(key);
    struct Node* node = dict->head;
    while(node != NULL){
        if(node->hash == hash){
            node->pair->value = value;
            return;
        }
        node = node->next;
    }
}

int keyExistsInDict(DICT *dict, int key){
    int count = 0;
    unsigned int hash = crc32b(key);
    struct Node* node = dict->head;
    while(node != NULL){
        if(node->hash == hash){
            count++;
        }
        node = node->next;
    }
    return count;
}


DICT* createEmptyDict(){
    DICT* dict = (DICT*) malloc(sizeof(DICT));
    dict->size = 0;
    dict->head = NULL;
    dict->tail = NULL;
    return dict;
}
DICT* createDict(char* key[], int value[]){
    int keySize = ARRAY_SIZE(key);
    int valueSize = ARRAY_SIZE(value);
    DICT* dict = createEmptyDict();

    if(keySize != valueSize){
        printf("Error: key and value arrays are not the same size");
        return NULL;
    }

    for(int i = 0; i < keySize; i++){
        addToDict(dict, key[i], value[i]);
    }
    return dict;
}

void freeDict(DICT *dict){
    struct Node* node = dict->head;
    struct Node* next;
    while(node != NULL){
        next = node->next;
        free(node->pair);
        free(node);
        node = next;
    }
    free(dict);
}

static unsigned int crc32b(unsigned char *message) {
   int i, j;
   unsigned int byte, crc, mask;

   i = 0;
   crc = 0xFFFFFFFF;
   while (message[i] != 0) {
      byte = message[i];            // Get next byte.
      crc = crc ^ byte;
      for (j = 7; j >= 0; j--) {    // Do eight times.
         mask = -(crc & 1);
         crc = (crc >> 1) ^ (0xEDB88320 & mask);
      }
      i = i + 1;
   }
   return ~crc;
}