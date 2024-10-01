#include <stdio.h>
#include <stdlib.h>

#define NROVAGAS 3

struct estacionamento{
    int vetor[NROVAGAS];
    int qtdade;
};

/**
 * Pode-se utilizar o typedef para definir um tipo dado, contudo,
 * é preciso ter ciência que a definição de uma struct (variável
 * composta heterogênea) não precisa ser feita usando o typedef.
 */

/**
 * Definindo um tipo com uma struct criada:

typedef struct estacionamento T_Estacionamento;
 */

/**
 * Definindo um tipo de dado em conjunto da declaração da 
 * struct:
 
typedef struct estacionamento{
    int vetor[NROVAGAS];
    int qtdade;
} T_Estacionamento;
 */
struct estacionamento criaEstacionamento(){
    struct estacionamento variavel;
    variavel.qtdade = -1;
    return variavel;
}

int estaCheio(struct estacionamento variavel){
    return variavel.qtdade == NROVAGAS-1?1:0;
}

void mostraEstacionamento(struct estacionamento garage){
    int i;
    printf("\nCarros estacionados: ");
    if(! (garage.qtdade < 0) ){
        for(i=0; i<garage.qtdade;i++){
            printf("%d - ", garage.vetor[i]);
        }
        printf("%d", garage.vetor[i]);
    }
}

struct estacionamento entraCarro(struct estacionamento garage, int placa){
    if(!estaCheio(garage)){
        garage.qtdade = garage.qtdade + 1;
        garage.vetor[garage.qtdade] = placa;
        printf("\nENTROU: %d", placa);
    }else{
        printf("\nESTACIONAMENTO CHEIO");
    }
    mostraEstacionamento(garage);
    return garage;
}

struct estacionamento saiCarro(struct estacionamento garage){
    int i;
    if(garage.qtdade > -1){
        printf("\nSAIU: %d", garage.vetor[0]);
        for(i=0; i<NROVAGAS-1;i++){
            garage.vetor[i] = garage.vetor[i+1];
        }
        garage.qtdade -= 1;
    }else{
        printf("\nESTACIONAMENTO VAZIO");
    }
    mostraEstacionamento(garage);
    return garage;
}

int main()
{
    struct estacionamento garagem;
    garagem = criaEstacionamento();
    garagem = saiCarro(garagem);
    garagem = entraCarro(garagem, 1234);
    garagem = entraCarro(garagem, 2345);
    garagem = entraCarro(garagem, 3456);
    garagem = entraCarro(garagem, 4567);
    garagem = saiCarro(garagem);
    garagem = entraCarro(garagem, 9876);
    garagem = entraCarro(garagem, 8765);
    garagem = saiCarro(garagem);
    garagem = saiCarro(garagem);
    return 0;
}