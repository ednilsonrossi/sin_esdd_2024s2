#include <stdio.h>
#include "lista.h"

int main(int argc, char const *argv[]) {
    
    List lista = create();

    insert(lista, "Matheus");
    insert(lista, "Natan");
    insert(lista, "Eduardo");
    insertAtBeggining(lista, "Airton");

    int max = size(lista);
    for (int i = 0; i < max; i++) {
        printf("%s \n", getIntoAt(lista, i));
    }

    return 0;
}
