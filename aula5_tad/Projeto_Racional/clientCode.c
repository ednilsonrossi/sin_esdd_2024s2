#include "racional.h"

/**
 * Estratégia do código cliente consiste em:
 *  - ler um número racional
 *  - acumular um racional em uma variável soma
 *  - contar a quantidade de racionais lidos
 *  - ao final da leitura, dividir a soma pela quantidade, obtendo assim a média aritmética.
 * 
 * 
 */
int main() {
    
    T_Racional soma, number, media;
    int n = 0;
    char continuar;
    soma = criarRacional(0, 1);

    do {
        printf("Digite o valor racional (numerador e denominador): \n");
        number = entradaRacional();
        soma = somaRacional(soma, number);
        destroiRacional(number);

        printf("Deseja Continuar a entrada de dados (S/n)? : ");
        scanf(" %c",&continuar);

        n += 1;
    } while (continuar != 'n' && continuar != 'N');

    number = criarRacional(1, n);
    media = multiplicaRacional(soma, number);
    printf("Média: ");
    imprimeRacional(media);
    printf("\n\n");

    destroiRacional(soma);
    destroiRacional(number);
    destroiRacional(media);
    return 0;
}
