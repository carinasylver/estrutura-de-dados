#ifndef filaSE_H
#define filaSE_H

#define SUCESSO 0
#define FILA_VAZIA 1
#define FALTOU_MEMORIA 2

typedef struct nodo Nodo;

typedef struct _dados
{
    int cod;
    float peso;
} Dados;

typedef struct nodo
{
    Dados info; 
    Nodo *prox; /
} Nodo;

typedef struct _filaSE
{
    Nodo *inicio;
    Nodo *fim;
} FilaSE;

void criaFila(FilaSE *fila);
int insere(FilaSE *fila, Dados dados);
int retira(FilaSE *fila, Dados *dados);
int estaVazia(FilaSE *fila);
int quantidadeDeNodos(FilaSE fila);
int consultaInicio(FilaSE *fila, Dados *dados);
void exibe(FilaSE fila);

#endif