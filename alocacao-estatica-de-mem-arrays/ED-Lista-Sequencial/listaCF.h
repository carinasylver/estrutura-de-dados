/*--------------------------------
 * Arquivo: listaCF.h
 */

#ifndef listaCF_H
#define listaCF_H

#define MAX_NODOS 5

#define SUCESSO 0
#define LISTA_VAZIA 1
#define LISTA_CHEIA 2
#define CODIGO_INEXISTENTE 3

typedef struct _listaCF ListaCF;

typedef struct _dados
{
    int cod;
    float peso;
} Dados;

typedef struct _listaCF
{
    int n;
    Dados v[MAX_NODOS];
} ListaCF;

void criaLista(ListaCF *lista);
int incluiNoFim(ListaCF *lista, Dados dado);
void exibe(ListaCF *lista);
int quantidadeDeNodos(ListaCF *lista);
int estaCheia(ListaCF *lista);
int estaVazia(ListaCF *lista);
int excluiDoFim(ListaCF *lista, Dados *dado);
int incluiNoInicio(ListaCF *lista, Dados dado);
int excluiDoInicio(ListaCF *lista, Dados *dado);
int consultaPorCodigo(ListaCF *lista, Dados *dado, int consultaCod);
int incluiAntes(ListaCF *lista, Dados dado, int cod);
int excluiNodo(ListaCF *lista, Dados *dado, int consultaCod);
int excluiNodo(ListaCF *lista, int consultaCod);


#endif