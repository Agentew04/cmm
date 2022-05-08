#include <stdlib.h>
#include <stdio.h>
#include "dict.h"
//#include "list.h"

int main(){
    DICT *dict = createEmptyDict();
    addToDict(dict, "key1", 1);
    addToDict(dict, "key2", 2);

    printf("%d\n", getValueFromDict(dict, "key3"));
}