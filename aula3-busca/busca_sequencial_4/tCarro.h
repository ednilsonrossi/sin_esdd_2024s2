struct carro{
    int placa;
    char marca[50];
	char modelo[50];
	char motorista[120];
};

void imprime_registro(struct carro registro);

void carrega_colecao(struct carro arquivo[]);