#include "setOfProjects.h"

struct setOfProjects {
    Info* arr_elements;
    int size;
    int max_size;
};

Set init() {
    Set mySet = malloc(sizeof(struct setOfProjects));
    if (mySet != NULL) {
        mySet->arr_elements = malloc(sizeof(Info) * DEFAULT_SET_SIZE);
        if (mySet->arr_elements != NULL) {
            mySet->size = 0;
            mySet->max_size = DEFAULT_SET_SIZE;
        } else {
            free(mySet);
            mySet = NULL;
        }
    }
    return mySet;
}

bool insert(Set mySet, Info element) {
    if (mySet->size == mySet->max_size) {
        Info* new_arr = malloc(sizeof(Info) * mySet->max_size * 2);
        if (new_arr == NULL) {
            return false;
        }
        for (int i = 0; i < mySet->max_size; i++) {
            new_arr[i] = mySet->arr_elements[i];
        }
        free(mySet->arr_elements);
        mySet->arr_elements = new_arr;
        mySet->max_size = mySet->max_size * 2;
    }
    mySet->arr_elements[mySet->size] = element;
    mySet->size += 1;
    return true;
}

Info getAt(Set mySet, int position) {
    if (position >= 0 && position < mySet->size) {
        return mySet->arr_elements[position];
    }
    return NULL;
}

int size(Set mySet) {
    return mySet->size;
}