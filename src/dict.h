struct KeyValuePair
{
    char *key;
    int value;
}; 

struct Node {
    struct Node *next;
    unsigned int hash;
    struct KeyValuePair *pair;
};

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
static struct Node* createNode(char* key, int value, struct Node *next);
/**
 * @brief Appends a value to the end of a dictonary
 * 
 * @param dict The dict object
 * @param key The key of the node
 * @param value The value to be appended
 */
void addToDict(DICT *dict, char *key, int value);
/**
 * @brief Removes an entry from the dictionary
 * 
 * @param list the dict object
 * @param key The key for the entry to be removed
 */
void removeFromDict(DICT *dict, int key);
/**
 * @brief Get the value associated with a key. If there are two
 * entries with the same key, the first one is returned. Check
 * with `keyExistsInDict()` if there are more than one entry with the same key.
 * 
 * @param dict The dict object
 * @param key The key for the value to be returned
 * @return the value associated with the key. Returns -1 if key is not found
 */
int getValueFromDict(DICT *dict, int key);
/**
 * @brief Changes the value associated with a key
 * 
 * @param dict The dict object
 * @param key The key for the value to be changed
 * @param value The new value to be associated with the key
 */
void editValueInDict(DICT *dict, int key, int value);
/**
 * @brief Get how many entries are in the dictionary with the same key
 * 
 * @param dict The dict object
 * @param key The key to be searched
 * @return The amount of entries with the same key
 */
int keyExistsInDict(DICT *dict, int key);

/**
 * @brief Create an empty Dictionary
 * 
 * @return A pointer to the dict object
 */
DICT* createEmptyDict();
/**
 * @brief Creates a dictionary based on two arrays. 
 * Must be of same size
 * 
 * @param keys The keys of the dictionary
 * @param values The values of the dictionary
 * @return A ptr to the dict object
 */
DICT* createDict(char* keys[], int values[]);
/**
 * @brief Frees an entire dictionary from memory
 * 
 * @param dict The dict object to be freed
 */
void freeDict(DICT *dict);

/**
 * @brief Hashes a string using crc32
 * 
 * @param message The string to be hashed,
 * must end with a null character
 */
static unsigned int crc32b(unsigned char *message);