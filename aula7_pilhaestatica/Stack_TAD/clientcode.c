#include "stack.h"
#include <stdio.h>

int main(int argc, char const *argv[]) {
    T_Stack pilha;

    pilha = init(5);

    for(int i = 5; i <= 12; i++) {
        if (push(pilha, i)) {
            printf("Empilhado %d\n", i);
        } else {
            printf("Pilha cheia\n");
        }
    }

    int dado;
    while(!isEmpty(pilha)) {
        if(pop(pilha, &dado)){
            printf("> %d\n", dado);
        }
    }

    destroy(pilha);
    
    return 0;
}
