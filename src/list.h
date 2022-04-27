typedef struct Node {
    struct Node *next;
    int value;
} NODE;

typedef struct LinkedList{
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
void printList(struct Node* head);

/**
 * @brief Allocates and create a node
 * 
 * @param value The value to be added
 * @param next The next node in the list, NULL if last
 * 
 * @return The pointer to the Node
 */
struct Node* createNode(int value, struct Node* next);

/**
 * @brief Frees the resources related to the nodes subsequent
 * 
 * @param head The first element in the list
 */
void freeList(struct Node* head);

/**
 * @brief Appends a value to the end of a list
 * 
 * @param node Any node from the list
 * @param value The value to be appended
 */
void appendToList(struct Node* node, int value);

/**
 * @brief Get the index of the first ocurrence of a value
 * 
 * @param head The first node in the list
 * @param value The value to be searched
 * @return The index of the first ocurrence of the value
 */
int getFirstIndex(struct Node* head, int value);

/**
 * @brief Removes the first ocurrence of a value from a list
 * 
 * @param head The first node from the list
 * @param value The value to be removed
 */
void removeValueFromList(struct Node* head, int value);