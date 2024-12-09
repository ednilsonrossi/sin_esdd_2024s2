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
    int a, b;
    T_Queue queueA = init(5);
    enqueue(queueA, 2);
    enqueue(queueA, 3);
    enqueue(queueA, 5);
    enqueue(queueA, 7);
    enqueue(queueA, 12);

    T_Queue queueB = init(8);
    enqueue(queueB, 3);
    enqueue(queueB, 6);
    enqueue(queueB, 5);
    enqueue(queueB, 7);
    enqueue(queueB, 10);
    enqueue(queueB, 11);
    enqueue(queueB, 13);
    enqueue(queueB, 0);

    T_Queue auxiliarA = init(5);
    T_Queue auxiliarB = init(8);

    printf("Relatório 1\n");
    while (!is_empty(queueA)) {
        dequeue(queueA, &a);
        enqueue(auxiliarA, a);
        while (!is_empty(queueB)) {
            dequeue(queueB, &b);
            enqueue(auxiliarB, b);

            if (a == b) {
                printf("%d\n", a);
            }
        }
        while (!is_empty(auxiliarB)) {
            dequeue(auxiliarB, &b);
            enqueue(queueB, b);
        }
    }
    while (!is_empty(auxiliarA)) {
        dequeue(auxiliarA, &a);
        enqueue(queueA, a);
    }

    return 0;
}













