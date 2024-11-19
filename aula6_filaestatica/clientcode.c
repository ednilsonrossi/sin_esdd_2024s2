#include <stdio.h>
#include "queue.h"

int main() {

    T_Queue fila;
    T_Info saiu;

    fila = init(5);

    printf("%s\n", enqueue(fila, 1) ? "Entrou" : "Não entrou");
    printf("%s\n", enqueue(fila, 2) ? "Entrou" : "Não entrou");
    printf("%s\n", enqueue(fila, 3) ? "Entrou" : "Não entrou");
    printf("%s\n", enqueue(fila, 4) ? "Entrou" : "Não entrou");
    printf("%s\n", enqueue(fila, 5) ? "Entrou" : "Não entrou");
    printf("%s\n", enqueue(fila, 6) ? "Entrou" : "Não entrou");
    printf("%s\n", enqueue(fila, 7) ? "Entrou" : "Não entrou");
    printf("%s\n", enqueue(fila, 8) ? "Entrou" : "Não entrou");

    while(!is_empty(fila)) {
        dequeue(fila, &saiu);
        printf("Saiu: %d\n", saiu);
    }

    printf("%s\n", enqueue(fila, 1) ? "Entrou" : "Não entrou");
    printf("%s\n", enqueue(fila, 2) ? "Entrou" : "Não entrou");
    printf("%s\n", enqueue(fila, 3) ? "Entrou" : "Não entrou");
    if (dequeue(fila, &saiu))       
        printf("Saiu: %d\n", saiu);
    if (dequeue(fila, &saiu))       
        printf("Saiu: %d\n", saiu);
    if (dequeue(fila, &saiu))       
        printf("Saiu: %d\n", saiu);
    if (dequeue(fila, &saiu))       
        printf("Saiu: %d\n", saiu);
    if (dequeue(fila, &saiu))       
        printf("Saiu: %d\n", saiu);

    printf("%s\n", enqueue(fila, 4) ? "Entrou" : "Não entrou");
    printf("%s\n", enqueue(fila, 5) ? "Entrou" : "Não entrou");
    printf("%s\n", enqueue(fila, 6) ? "Entrou" : "Não entrou");
    printf("%s\n", enqueue(fila, 7) ? "Entrou" : "Não entrou");
    printf("%s\n", enqueue(fila, 8) ? "Entrou" : "Não entrou");

    destroy(fila);
    return 0;
}
