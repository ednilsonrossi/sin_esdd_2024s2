#include <stdio.h>
#include "lse.h"

int main(int argc, char const *argv[]) {
    Info element;
    List myList = createList();

    insertList(myList, 5);
    insertList(myList, 10);
    insertList(myList, 15);
    insertList(myList, 20);
    insertList(myList, 25);
    insertList(myList, 30);
    insertList(myList, 35);
    insertList(myList, 40);
    insertList(myList, 45);
    insertList(myList, 50);

    printf("Lista: \n");
    for (int i = 0; i < size(myList); i++) {
        element = getInfoAt(myList, i);
        printf("[%d]: %d\n", i, element);
    }

    destroyList(myList);
    
    return 0;
}
