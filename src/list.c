#include <stdlib.h>
#include <stdio.h>
#include "list.h"
#include <stdbool.h>

// #region Creates

static struct Node *createNode(int value, struct Node *next)
{
    struct Node *node = malloc(sizeof *node);
    node->value = value;
    node->next = next;
    return node;
}

LIST *createList(int *values, int size)
{
    // check if new list should be empty
    LIST *list = malloc(sizeof *list);
    list->size = size;
    if (size == 0 || values == NULL)
    {
        list->head = NULL;
        list->tail = NULL;
    }
    else
    {
        list->head = createNode(values[0], NULL);
        list->tail = list->head;
    }

    // if empty the loop will not activate
    for (int i = 1; i < size; i++)
    {
        appendToList(list, values[i]);
        list->tail = list->tail->next;
    }
    return list;
}

// #endregion

// #region interacts

void appendToList(LIST *list, int value)
{
    struct Node *newNode = createNode(value, NULL);

    if (list->head == NULL || list->tail==NULL || list->size==0)
    {
        list->head = newNode;
        list->tail = newNode;
    }else{
        list->tail->next = newNode;
        list->tail = newNode;
    }
    list->size++;
}

void removeFirstValueFromList(LIST *list, int value)
{
    struct Node *current = list->head;
    struct Node *previous = NULL;

    while (current != NULL)
    {
        if (current->value == value)
        {
            // if the value is the first element
            if (previous == NULL) list->head = current->next;
            else previous->next = current->next;
            free(current);
            list->size--;
            return;
        }
        else
        {
            // go to next node
            previous = current;
            current = current->next;
        }
    }
}

// #endregion

// #region search

bool existsInList(LIST* list, int value)
{
    struct Node *current = list->head;
    while (current != NULL)
    {
        if (current->value == value)
            return true;
        current = current->next;
    }
    return false;
}

int getFirstIndex(LIST *list, int value)
{
    struct Node *current = list->head;
    int index = 0;

    while (current != NULL)
    {
        if (current->value == value) return index;
        else
        {
            index += 1;
            current = current->next;
        }
    }
    return -1;
}

// #endregion


void printList(LIST *list)
{
    struct Node *current = list->head;

    while (current != NULL)
    {
        printf("%d\n", current->value);
        current = current->next;
    }
}

void freeList(LIST *list)
{
    struct Node *temp;
    while (list->head != NULL)
    {
        temp = list->head;
        list->head = list->head->next;
        free(temp);
    }
    free(list);
}


int main()
{
    int values[] = {1, 2, 3, 4, 5, 6, 7, 8, 9, 10};

    LIST* list = createList(&values[0], (sizeof values)/sizeof(int));
    //LIST *list = createList(NULL, 0);

    appendToList(list, 11);
    printList(list);

    freeList(list);
}