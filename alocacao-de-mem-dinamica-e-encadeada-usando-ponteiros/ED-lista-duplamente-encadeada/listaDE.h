#include <stdio.h>
#include <stdlib.h>

#define SUCESSO 0
#define LISTA_VAZIA 1
#define FALTOU_MEMORIA 2
#define CODIGO_INEXISTENTE 3

typedef struct nodo Nodo;

typedef struct _dados
{
    int cod;
    float peso;
} Dados;
typedef struct nodo
{
    Dados info;
    Nodo *ant;
    Nodo *prox;
} Nodo;

typedef struct _listaDE
{
    Nodo *inicio;
    Nodo *fim;
    int n;
} ListaDE;

void criaLista(ListaDE *lista);
int incluiNoInicio(ListaDE *lista, Dados dado);
void exibe(ListaDE lista);
int quantidadeDeNodos(ListaDE lista);
int estaVazia(ListaDE *lista);
int excluiDoInicio(ListaDE *lista, Dados *dados);
int incluiNoFim(ListaDE *lista, Dados dados);
int excluiDoFim(ListaDE *lista, Dados *dados);
int incluiDepois(ListaDE *lista, Dados dados, int cod);
int excluiNodo(ListaDE *lista, Dados *dados, int cod);
int consultaPorCodigo(ListaDE *lista, Dados *dados, int consultaCod);