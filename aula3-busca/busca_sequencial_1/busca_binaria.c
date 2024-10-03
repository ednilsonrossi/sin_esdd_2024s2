/**
 * Autor..: Ednilson Rossi
 * Contato: ednilsonrossi@ifsp.edu.br
*/


/* Implementação da operação de busca sequencial */
#include <stdio.h>
#include "uteis.h"

#define MAX 14

int busca_binaria(int [], int, int);

void main(){
	int arquivo[MAX];
	int chave;
	
	carrega_vetor_ordenado(arquivo, 3, MAX);
	imprime_vetor(arquivo, MAX);
	
	chave = 10;
	
	if( busca_binaria(arquivo, MAX, chave) )
		printf("Existe a chave %d no arquivo.\n", chave);
	else
		printf("Não existe a chave %d no arquivo.\n", chave);

}

int busca_binaria(int file[], int size, int key){
		int achou = FALSE;
		int inicio, fim, meio;
		
		inicio=0; 
		fim = size-1;
		meio = (inicio + fim) / 2;
		
		while(inicio <= fim && !achou){
			if( file[meio] == key ){
				achou = TRUE;
			}else{
				if (key < file[meio]){
					fim = meio - 1;
				}else{
					inicio = meio + 1;
				}
				meio = (inicio + fim) / 2;
			}
		}
		
		return achou;
}