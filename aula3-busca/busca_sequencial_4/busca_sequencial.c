/**
 * Autor..: Ednilson Rossi
 * Contato: ednilsonrossi@ifsp.edu.br
*/


/* Implementação da operação de busca sequencial em arquivo composto por registros*/
#include <stdio.h>
#include "uteis.h"
#include "tCarro.h"

#define TAM 7

int busca_sequencial(struct carro file[], int size, int placa);

int main(int argc, char const *argv[]){
    int input;
	struct carro arquivo[TAM];
	
	carrega_colecao(arquivo);
    
    printf("Dados\n\n");
    for(int index=0; index < TAM; index++){
        imprime_registro(arquivo[index]);
    }

    do{
        printf("\nPlaca desejada (0 -> Sair): ");
        scanf("%d", &input);
        if(busca_sequencial(arquivo, TAM, input) == TRUE){
            printf("Acesso permitido.\n");
        }else{
            printf("Acesso negado.\n");
        }
    }while(input != 0);

    return 0;
}

int busca_sequencial(struct carro file[], int size, int placa){
    int founded = FALSE;
    for(int i = 0; i < size && founded == FALSE; i++){
        if(file[i].placa == placa){
            founded = TRUE;
        }
    }
    return founded;
}