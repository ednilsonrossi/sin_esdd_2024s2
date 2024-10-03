#include "tCarro.h"
#include <string.h>
#include <stdio.h>


void imprime_registro(struct carro registro){
    printf("Proprietario: %s \tPlaca: %d \tVeiculo: %s/%s\n", registro.motorista, registro.placa, registro.marca, registro.modelo);
}

void carrega_colecao(struct carro arquivo[]){
    int index = 0;
    arquivo[index].placa = 2345;
    strcpy(arquivo[index].motorista, "EDUARDO");
    strcpy(arquivo[index].marca, "FIAT");
    strcpy(arquivo[index].modelo, "PUNTO");

    index++;
    arquivo[index].placa = 9999;
    strcpy(arquivo[index].motorista, "PAULO");
    strcpy(arquivo[index].marca, "FORD");
    strcpy(arquivo[index].modelo, "FIESTA");

    index++;
    arquivo[index].placa = 8765;
    strcpy(arquivo[index].motorista, "ROBERTO");
    strcpy(arquivo[index].marca, "TOYOTA");
    strcpy(arquivo[index].modelo, "HILLUX");

    index++;
    arquivo[index].placa = 6754;
    strcpy(arquivo[index].motorista, "MARCELO");
    strcpy(arquivo[index].marca, "HONDA");
    strcpy(arquivo[index].modelo, "FIT");

    index++;
    arquivo[index].placa = 6781;
    strcpy(arquivo[index].motorista, "BRUNO");
    strcpy(arquivo[index].marca, "PEGEOUT");
    strcpy(arquivo[index].modelo, "308");

    index++;
    arquivo[index].placa = 7777;
    strcpy(arquivo[index].motorista, "ANTONIO");
    strcpy(arquivo[index].marca, "VW");
    strcpy(arquivo[index].modelo, "GOL");

    index++;
    arquivo[index].placa = 6171;
    strcpy(arquivo[index].motorista, "VANESSA");
    strcpy(arquivo[index].marca, "GM");
    strcpy(arquivo[index].modelo, "CRUZE");
}