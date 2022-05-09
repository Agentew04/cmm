#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include "dict.h"
//#include "list.h"

int main(){
    DICT* dict = createEmptyDict();
    addToDict(dict, "hello", 1);


    char input[20];
    int val;
    do{
        printf("Enter key: ");
        scanf("%s", input);
        printf("Enter value (type 0 to end): ");
        scanf("%d", &val);

        if(val == 0){
            break;
        }
        addToDict(dict, input, val);
    }while(val!=0);

    printDict(dict);
}