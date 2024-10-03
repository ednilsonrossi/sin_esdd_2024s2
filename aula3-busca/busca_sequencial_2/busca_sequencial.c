/**
 * Autor..: Ednilson Rossi
 * Contato: ednilsonrossi@ifsp.edu.br
*/


/* Implementação da operação de busca sequencial */
#include <stdio.h>
#include "uteis.h"

#define TAM 12

int busca_sequencial(int file[], int size, int key);

int main(int argc, char const *argv[]){
	int arquivo[TAM];
    int chave = 100;
	
	carrega_vetor_aleatorio(arquivo, TAM, 3);
	imprime_vetor(arquivo, TAM);

    if(busca_sequencial(arquivo, TAM, chave) == TRUE)
        printf("A chave %d existe no arquivo.\n", chave);
    else
        printf("A chave %d NÃO existe no arquivo.\n", chave);

    return 0;
}

int busca_sequencial(int file[], int size, int key){
    int founded = FALSE;
    for(int i = 0; i < size && founded == FALSE; i++){
        if(file[i] == key){
            founded = TRUE;
        }
    }
    return founded;
}