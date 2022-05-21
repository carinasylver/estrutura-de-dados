#include <stdio.h>
#include <stdlib.h>
#include "listaDE.h"

void criaLista(ListaDE *lista)
{
    lista->inicio = NULL;
    lista->fim = NULL;
    lista->n = 0;
}
int incluiNoInicio(ListaDE *lista, Dados dados)
{
    Nodo *pNodo;

    pNodo = (Nodo *)malloc(sizeof(Nodo));

    if (pNodo == NULL)
    {
        return FALTOU_MEMORIA;
    }
    else
    {
        pNodo->info = dados;
        pNodo->prox = lista->inicio;
        if (estaVazia(lista))
        {
            lista->fim = pNodo;
        }
        else
        {
            lista->inicio->ant = pNodo;
        }
        lista->inicio = pNodo;
        lista->n++;
        return SUCESSO;
    }
}
void exibe(ListaDE lista)
{
    Nodo *pAux;
    pAux = lista.inicio;
    puts("--------------------------------------------------------------------");
    printf("--------------Exibindo a LISTA DUPLAMENTE ENCADEADA-----------------\n");
    printf("enderecoInicio -> %p \n", lista.inicio);
    puts("--------------------------------------------------------------------");
    printf("[EnderecoAnterior][EnderecoNodoAtual] [cod] [peso] [EnderecoProx]\n");
    while (pAux != NULL)
    {
        printf(" %p  -  %p -  %5d   %.2f -  %p   \n", pAux->ant, pAux, pAux->info.cod, pAux->info.peso, pAux->prox);

        pAux = pAux->prox;
        puts("-------------------------------------------------------------------");
    }
    printf("EnderecoFim -> %p - N = %d\n", lista.fim, lista.n);
    puts("---------------------------------------------------------------------");
}
int quantidadeDeNodos(ListaDE lista)
{
    return lista.n;
}
int estaVazia(ListaDE *lista)
{
    if (lista->inicio == NULL)
    {
        return 1;
    }
    else
    {
        return 0;
    }
}
int excluiDoInicio(ListaDE *lista, Dados *dados)
{
    Nodo *pNodo;

    if (estaVazia(lista))
    {
        return LISTA_VAZIA;
    }
    else
    {
        *dados = lista->inicio->info;
        pNodo = lista->inicio;
        lista->inicio = pNodo->prox;
        if (lista->fim == pNodo)
        {
            lista->fim = NULL;
        }
        else
        {
            lista->inicio->ant = NULL;
        }
        free(pNodo);
        lista->n--;
        return SUCESSO;
    }
}
int incluiNoFim(ListaDE *lista, Dados dados)
{
    Nodo *pNodo;
    pNodo = (Nodo *)malloc(sizeof(Nodo));

    if (pNodo == NULL)
    {
        return FALTOU_MEMORIA;
    }
    pNodo->info = dados;
    pNodo->ant = lista->fim;
    if (estaVazia(lista))
    {
        lista->inicio = pNodo;
    }
    else
    {
        lista->fim->prox = pNodo;
    }
    lista->fim = pNodo;
    lista->n++;
    return SUCESSO;
}
int excluiDoFim(ListaDE *lista, Dados *dados)
{
    Nodo *pNodo;

    if (estaVazia(lista))
    {
        return LISTA_VAZIA;
    }
    else
    {
        pNodo = lista->inicio;
        while (pNodo->prox != NULL)
        {
            pNodo = pNodo->prox;
        }
        if (pNodo == lista->inicio)
        {
            *dados = pNodo->info;
            lista->inicio = pNodo->prox;
        }
        else
        {
            *dados = pNodo->info;
            pNodo->ant->prox = pNodo->prox;
            lista->fim = pNodo->ant;
        }
        free(pNodo);
        lista->n--;
        return SUCESSO;
    }
}
int incluiDepois(ListaDE *lista, Dados dados, int cod)
{
    Nodo *pNodo, *pAux;
    pNodo = (Nodo *)malloc(sizeof(Nodo));

    if (pNodo == NULL)
    {
        return FALTOU_MEMORIA;
    }
    if (estaVazia(lista))
    {
        return LISTA_VAZIA;
    }
    pAux = lista->inicio;
    while (pAux != NULL && pAux->info.cod != cod)
    {
        pAux = pAux->prox;
    }
    if (pAux == NULL)
    {
        return CODIGO_INEXISTENTE;
    }
    pNodo->info = dados;
    pNodo->prox = pAux->prox;
    pAux->prox = pNodo;
    pNodo->ant = pAux;
    lista->n++;
    return SUCESSO;
}
int excluiNodo(ListaDE *lista, Dados *dados, int cod)
{
    Nodo *pNodo;
    pNodo = lista->inicio;
    if (estaVazia(lista))
    {
        return LISTA_VAZIA;
    }
    while (pNodo != NULL && pNodo->info.cod != cod)
    {
        pNodo = pNodo->prox;
    }
    if (pNodo == NULL)
    {
        return CODIGO_INEXISTENTE;
    }
    *dados = pNodo->info;
    if (pNodo == lista->inicio)
    {
        lista->inicio = pNodo->prox;
    }
    else if (lista->fim == pNodo)
    {
        pNodo->ant->prox = pNodo->prox;
        lista->fim = pNodo->ant;
    }
    else
    {
        pNodo->ant->prox = pNodo->prox;
        pNodo->prox->ant = pNodo->ant;
    }
    free(pNodo);
    lista->n--;
    return SUCESSO;
}
int consultaPorCodigo(ListaDE *lista, Dados *dados, int consultaCod)
{
    Nodo *pNodo;
    pNodo = lista->inicio;
    while (pNodo != NULL && pNodo->info.cod != consultaCod)
    {
        pNodo = pNodo->prox;
    }
    if (pNodo == NULL)
    {
        return CODIGO_INEXISTENTE;
    }
    *dados = pNodo->info;
    return SUCESSO;
}
