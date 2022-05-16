#ifndef pilhaSE_H
#define pilhaSE_H

#define SUCESSO 0
#define PILHA_VAZIA 1
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
    Nodo *prox; 
} Nodo;
typedef struct _pilhaSE
{
    Nodo *topo;
} PilhaSE;

void criaPilha(PilhaSE *pilha);
int empilha(PilhaSE *pilha, Dados dados);
int desempilha(PilhaSE *pilha, Dados *dados);
void exibe(PilhaSE pilha);
int quantidadeDeNodos(PilhaSE pilha);
int pilhaVazia(PilhaSE *pilha);
int consultaTopo(PilhaSE *pilha, Dados dados);

#endif