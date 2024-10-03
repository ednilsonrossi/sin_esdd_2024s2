/**
 * Autor..: Ednilson Rossi
 * Contato: ednilsonrossi@ifsp.edu.br
*/


/* Implementação da operação de busca sequencial para arquivo classificado */
#include <stdio.h>
#include "uteis.h"

#define TAM 12

int busca_sequencial(int file[], int size, int key);

int main(int argc, char const *argv[]){
	int arquivo[TAM];
    int chave = 100;
	
	carrega_vetor_ordenado(arquivo, 50, TAM);
	imprime_vetor(arquivo, TAM);

    if(busca_sequencial(arquivo, TAM, chave) == TRUE)
        printf("A chave %d existe no arquivo.\n", chave);
    else
        printf("A chave %d NÃO existe no arquivo.\n", chave);

    return 0;
}

int busca_sequencial(int file[], int size, int key){
    int founded = FALSE;
    for(int i = 0; i < size && file[i] <= key; i++){
        if(file[i] == key){
            founded = TRUE;
        }
    }
    return founded;
}