#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h>

typedef int T_Info;

struct queue {
    T_Info* elements;
    int maxsize;
    int size;
    int last;
    int first;
};

typedef struct queue* T_Queue;


T_Queue init(int max_size) {
    if (max_size < 1) {
        return NULL;
    }

    T_Queue queue = malloc( sizeof(struct queue) );
    if (queue != NULL) {
        queue->maxsize = max_size;
        queue->elements = malloc (sizeof(T_Info) * queue->maxsize);
        if (queue->elements == NULL) {
            free(queue);
            queue = NULL;
        } else {
            queue->first = 0; 
            queue->last = -1;
            queue->size = 0;
        }
    }

    return queue;
}

void destroy(T_Queue queue) {
    free(queue->elements);
    free(queue);
}

bool is_full(T_Queue queue) {
    return queue->size == queue->maxsize;
}

bool is_empty(T_Queue queue) {
    return queue->size == 0;
}

bool enqueue(T_Queue queue, T_Info element) {
    if (queue == NULL) {
        return false;
    }

    if (!is_full(queue)) {
        queue->last += 1;
        if (queue->last == queue->maxsize) {
            queue->last = 0;
        }
        queue->elements[queue->last] = element;
        queue->size += 1;
        return true;
    }

    return false;
}

bool dequeue(T_Queue queue, T_Info* elemento) {
    if (queue != NULL) {
        if (!is_empty(queue)) {
            *elemento = queue->elements[queue->first];
            queue->first += 1;
            if (queue->first == queue->maxsize) {
                queue->first = 0;
            }
            queue->size -= 1;
            return true;
        }
    }

    return false;
}


int main() {
    T_Queue fila;
    T_Queue auxiliar;
    T_Info input;
    fila = init(20);

    for(int i = 0; i < 20; i++) {
        printf("Digite valor: ");
        scanf("%d", &input);
        if (enqueue(fila, input) ) {
            printf("%d inserido com sucesso.\n", input);
        } else {
            printf("Erro ao inserir %d.\n", input);
        }
    }

    auxiliar = init(20);
    while (!is_empty(fila)) {
        dequeue(fila, &input);

        if (input == 0) {
            enqueue(auxiliar, input);
        } else if (input % 2 == 1) {
            enqueue(auxiliar, input);
        }
    }

    while (!is_empty(auxiliar)) {
        dequeue(auxiliar, &input);
        enqueue(fila, input);
    }

    printf("Inicio >\n");
    while(!is_empty(fila)) {
        dequeue(fila, &input);
        printf("%d\n", input);
    }
    printf("< Fim\n");

    return 0;
}

