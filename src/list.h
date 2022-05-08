// this is not necessary, but if optimizes compile
#define EXPORT __declspec(dllexport)

typedef struct Node {
    struct Node *next;
    int value;
} NODE;

typedef struct List{
    struct Node *head;
    struct Node *tail;
    int size;
} LIST;

/**
 * @brief Prints all the elements in the list
 * 
 * @param head The first node in the list
 * @param value The value contained in this node
 */
void printList(LIST* head);

/**
 * @brief Appends a value to the end of a list
 * 
 * @param node Any node from the list
 * @param value The value to be appended
 */
void appendToList(LIST* list, int value);



/**
 * @brief Frees the resources related to the nodes subsequent
 * 
 * @param head The first element in the list
 */
void freeList(LIST* head);

/**
 * @brief Get the index of the first ocurrence of a value
 * 
 * @param list The first node in the list
 * @param value The value to be searched
 * @return The index of the first ocurrence of the value.
 * If the value is not found, returns -1
 */
int getFirstIndex(LIST *list, int value);

/**
 * @brief Removes the first ocurrence of a value from a list
 * 
 * @param list The first node from the list
 * @param value The value to be removed
 */
void removeFirstValueFromList(LIST *list, int value);

/**
 * @brief Creates a list based on a array. If values or
 * size are respectively NULL or 0, the list will be empty
 * 
 * @param values a pointer to many values
 * @param size how many values are in the array/pointer
 * @return A pointer to the list object
 */
LIST* createList(int* values, int size);