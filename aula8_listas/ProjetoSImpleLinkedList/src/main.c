#include <stdio.h>
#include "linkedList.h"

int main() {
    Info element;
    List myList = createList();
    List emptyList = createList();

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

    insertAtBeginningList(myList, 24);
    
    printf("Lista: \n");
    for (int i = 0; i < size(myList); i++) {
        element = getInfoAt(myList, i);
        printf("[%d]: %d\n", i, element);
    }

    //printf("Existe 35? %d\n", hasElement(myList, 35));
    //printf("Existe 12? %d\n", hasElement(myList, 12));
    //printf("Existe 35 na lista vazia? %d\n", hasElement(emptyList, 35));

    removeAt(myList, 0);
    removeAt(myList, 9);
    removeAt(myList, 4);
    printf("Lista: \n");
    for (int i = 0; i < size(myList); i++) {
        element = getInfoAt(myList, i);
        printf("[%d]: %d\n", i, element);
    }

    destroyList(myList);
    myList = NULL;

    return 0;
}
