#include "lib.h"


int main() {
    
    int vetor[100];

    gerar_crescente(vetor, 100);

    for(int i = 0; i < 100; i++ ) {
        printf("%6d ", vetor[i]);
    }

    return 0;
}
