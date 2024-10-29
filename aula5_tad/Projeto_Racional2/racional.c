#include <stdbool.h>
#include <stdlib.h>
#include <stdio.h>


/**
 * Definição da estrutura de dados
 */
struct racional {
    int numerador;
    int denominador;
};

/**
 * Definição de tipo de dados
 */
typedef struct racional T_Racional;


/**
 * Definição das operações do TAD.
 */
T_Racional criarRacional(int numerador, int denominador);

T_Racional somaRacional(T_Racional racionalA, T_Racional racionalB);

T_Racional multiplicaRacional(T_Racional racionalA, T_Racional racionalB);

void imprimeRacional(T_Racional racional);

T_Racional entradaRacional();

void simplificarRacional(T_Racional* racionalPtr);

bool ehValidoRacional(T_Racional racional);

int mdc(int a, int b);


/**
 * Programa cliente, especificamente o main() que utiliza o TAD.
 */
int main() {
    
    T_Racional soma, number, media;
    int n = 0;
    char continuar;

    /* Inicialização da soma com zero, ou seja, 0/1 */

    /**
     * Nas duas linhas abaixo temos que o cliente code está acessando
     * diretamente os dados do TAD definido, lembrando que o TAD consiste
     * em um conjunto de dados, aqui numerador e denominador, e um conjunto
     * de operações que atuam sobre esses dados. Nessas suas linhas está sendo
     * atribuído o valor zero para numerador de denominador diretamente nos
     * dados, observe que é um erro, pois denominador não pode ser zero, e 
     * isso caracteriza a QUEBRA DO TAD, visto que é característica
     * do TAD que os dados sejam manipulados exclusivamente pelas operações
     * do TAD. Assim, as duas linhas abaixo são um ERRO, e lembre-se: NÃO QUEBRE O TAD.
     */
    soma.numerador = 0;
    soma.denominador = 0;

    soma = criarRacional(0, 1);

    do {
        printf("Digite o valor racional (numerador e denominador): \n");
        number = entradaRacional();
        soma = somaRacional(soma, number);

        printf("Deseja Continuar a entrada de dados (S/n)? : ");
        scanf(" %c",&continuar);

        n += 1;
    } while (continuar != 'n' && continuar != 'N');

    number = criarRacional(1, n);
    media = multiplicaRacional(soma, number);
    printf("Média: ");
    imprimeRacional(media);
    printf("\n\n");

    return 0;
}


/**
 * Implementação das operações do TAD.
 */

T_Racional criarRacional(int numerador, int denominador) {
    T_Racional ptr;

    ptr.numerador = numerador;
    ptr.denominador = denominador;

    if (!ehValidoRacional(ptr)) {
        ptr.numerador = 0;
        ptr.denominador = 1;
    }

    return ptr;
}

T_Racional somaRacional(T_Racional racionalA, T_Racional racionalB) {
    T_Racional soma;
    soma = criarRacional(0, 1);

    soma.numerador = racionalA.numerador * racionalB.denominador + 
                            racionalB.numerador * racionalA.denominador;
    soma.denominador = racionalA.denominador * racionalB.denominador;

    simplificarRacional(&soma);
    return soma;
}

T_Racional multiplicaRacional(T_Racional racionalA, T_Racional racionalB) {
    T_Racional racional;
    racional = criarRacional(0, 1);

    racional.numerador = racionalA.numerador * racionalB.numerador;
    racional.denominador = racionalA.denominador * racionalB.denominador;

    simplificarRacional(&racional);
    return racional;
}

void imprimeRacional(T_Racional racional) {
    printf("%d/%d", racional.numerador, racional.denominador);
}

T_Racional entradaRacional() {
    int numerador, denominador;
    scanf("%d", &numerador);
    scanf("%d", &denominador);
    T_Racional racional = criarRacional(numerador, denominador);
    return racional;
}

void simplificarRacional(T_Racional* racionalPtr) {
    int vMdc = mdc(racionalPtr->numerador, racionalPtr->denominador );
    racionalPtr->numerador = racionalPtr->numerador / vMdc;
    racionalPtr->denominador = racionalPtr->denominador / vMdc;
}

bool ehValidoRacional(T_Racional racional) {
    return racional.denominador != 0;
}

int mdc(int a, int b) {
    int resto;
    do {
        resto = a % b;
        a = b;
        b = resto;
    } while (resto != 0);
    return a;
}