#include <stdio.h>
#include <stdlib.h>
#include "dict.h"
#include <string.h>

/**
 * @brief Hashes a string using crc32
 * 
 * @param message The string to be hashed,
 * must end with a null character
 */
static unsigned int crc32b(char *message);
/**
 * @brief Allocates and create a node
 * 
 * @param key The key of the node
 * @param value The value to be added
 * @param next The next node in the list, NULL if last
 * 
 * @return The pointer to the Node
 */
static struct Node* createNode(char* key, int value, struct Node *next);

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
    // copy string
    char* keyCopy = (char*) malloc(strlen(key) + 1);
    strcpy(keyCopy, key);

    // create node
    struct Node* node = createNode(keyCopy, value, NULL);
    if(dict->head == NULL){
        dict->head = node;
        dict->tail = node;
    }else{
        dict->tail->next = node;
        dict->tail = node;
    }
    dict->size++;
}

void removeFromDict(DICT *dict, char *key){
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

int getValueFromDict(DICT *dict, char *key){
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

void editValueInDict(DICT *dict, char *key, int value){
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

int keyExistsInDict(DICT *dict, char *key){
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


DICT* createEmptyDict(void){
    DICT* dict = (DICT*) malloc(sizeof(DICT));
    dict->size = 0;
    dict->head = NULL;
    dict->tail = NULL;
    return dict;
}
DICT* createDict(char **key, int *values, int size){
    DICT* dict = createEmptyDict();

    for(int i = 0; i < size; i++){
        addToDict(dict, key[i], values[i]);
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

void printDict(DICT *dict){
    struct Node* node = dict->head;
    printf("[");
    while(node != NULL){
        printf("\n {'%s', %d},", node->pair->key, node->pair->value);
        node = node->next;
    }
    printf("\b \n]");
}

static unsigned int crc32b(char *message) {
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