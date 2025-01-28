#include <stdio.h>
#include "linkedList.h"

int main() {
    List lista = createList();
    
    insertList(lista, 25);
    insertList(lista, 30);
    insertList(lista, 10);
    insertList(lista, 6);
    insertList(lista, 60);
    insertList(lista, 33);
    insertList(lista, 18);
    insertList(lista, 30);
    insertList(lista, 6);
    insertList(lista, 6);
    insertList(lista, 33);

    /*
    printf("Chave: 06 - %d ocorrências.\n", countKey(lista, 6));
    printf("Chave: 10 - %d ocorrências.\n", countKey(lista, 10));
    printf("Chave: 61 - %d ocorrências.\n", countKey(lista, 61));
    */


    insertAtPositionList(lista, -5, 7);
    insertAtPositionList(lista, 0, 14);
    insertAtPositionList(lista, 4, 21);
    insertAtPositionList(lista, 90, 28);

    printf("Lista: \n");
    for (int i = 0; i < size(lista); i++) {
        printf("|%d|-> ", getInfoAt(lista, i));
    }
    printf("NULL\n");

    return 0;
}
