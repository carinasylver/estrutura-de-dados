#ifndef listaSE_H
#define listaSE_H

#define SUCESSO 0
#define LISTA_VAZIA 1
#define FALTOU_MEMORIA 2
#define CODIGO_INEXISTENTE 3

typedef struct no Nodo;
typedef struct _dados
{
    int cod;
    float peso;
} Dados;
typedef struct no
{
    Dados info;
    Nodo *prox;
} Nodo;
typedef struct _listaSE
{
    Nodo *inicio;
} ListaSE;

void criaLista(ListaSE *lista);
int incluiNoInicio(ListaSE *lista, Dados dados);
void exibe(ListaSE lista);
int quantidadeDeNodos(ListaSE lista);
int estaVazia(ListaSE *lista);
int excluiDoInicio(ListaSE *lista, Dados *dados);
int incluiNoFim(ListaSE *lista, Dados dados);
int excluiDoFim(ListaSE *lista, Dados *dados);
int incluiDepois(ListaSE *lista, Dados dados, int cod);
int excluiNodo(ListaSE *lista, Dados *dados, int cod);
int consultaPorCodigo(ListaSE *lista, Dados *dados, int consultaCod);

#endif
