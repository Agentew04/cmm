typedef struct Node {
    struct Node *next;
    int key;
    int value;
} NODE;

typedef struct Dict{
    struct Node *head;
    struct Node *tail;
    int size;
} DICT;

/**
 * @brief Allocates and create a node
 * 
 * @param key The key of the node
 * @param value The value to be added
 * @param next The next node in the list, NULL if last
 * 
 * @return The pointer to the Node
 */
static struct Node* createNode(int key, int value, struct Node* next);

/**
 * @brief Appends a value to the end of a dictonary
 * 
 * @param dict The dict object
 * @param key The key of the node
 * @param value The value to be appended
 */
void appendToDict(DICT* list, int key, int value);

/**
 * @brief Creates a new dictonary base on two arrays, 
 * one with the keys and the other with the values. 
 * Note that the arrays must have the same size
 * 
 * @param keys A ptr to an array
 * @param values A ptr to an array
 * @return A pointer to the dict object. 
 * NULL if the size of the arrays are not equal
 */
DICT* createDict(int* keys, int* values);