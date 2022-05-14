#include "listaSE.h"
#include <stdio.h>
#include <stdlib.h>

void criaLista(ListaSE *lista)
{
    lista->inicio = NULL;
}
int incluiNoInicio(ListaSE *lista, Dados dados)
{
    Nodo *nNodo = (Nodo *)malloc(sizeof(Nodo));

    if (nNodo == NULL)
    {
        return FALTOU_MEMORIA;
    }
    else
    {
        nNodo->info = dados;
        nNodo->prox = lista->inicio;
        lista->inicio = nNodo;
        return SUCESSO;
    }
}
void exibe(ListaSE lista)
{
    Nodo *pAux = lista.inicio;
    puts("--------------------------------------------------------");
    printf("[EnderecoInicio]\n %p\n", lista.inicio);
    puts("--------------------------------------------------------");
    printf("Exibindo a LISTA ENCADEADA:\n");
    printf("[EnderecoNodo]       [cod] [peso] [EnderecoProxNodo]\n");
    while (pAux != NULL)
    {
        printf("  %p -   %3d   %.2f -  %p   \n", pAux, pAux->info.cod, pAux->info.peso, pAux->prox);
        puts("--------------------------------------------------------");
        pAux = pAux->prox;
    }
    printf("[EnderecoFim]: NULL\n");
    puts("--------------------------------------------------------");
}
int quantidadeDeNodos(ListaSE lista)
{

    Nodo *pAux = lista.inicio;
    int cont = 0;

    while (pAux != NULL)
    {
        cont++;
        pAux = pAux->prox;
    }
    return (cont);
}
int estaVazia(ListaSE *lista)
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
int excluiDoInicio(ListaSE *lista, Dados *dados)
{
    Nodo *nNodo;

    if (estaVazia(lista))
    {
        return LISTA_VAZIA;
    }
    else
    {
        *dados = lista->inicio->info;
        nNodo = lista->inicio;
        lista->inicio = lista->inicio->prox;
        free(nNodo);
        return SUCESSO;
    }
}
int incluiNoFim(ListaSE *lista, Dados dados)
{
    Nodo *nNodo = (Nodo *)malloc(sizeof(Nodo));

    if (nNodo == NULL)
    {
        return FALTOU_MEMORIA;
    }
    nNodo->info = dados;
    nNodo->prox = NULL;
    if (estaVazia(lista))
    {
        lista->inicio = nNodo;
        return SUCESSO;
    }
    else
    {
        Nodo *aux = lista->inicio;
        while (aux->prox != NULL)
        {
            aux = aux->prox;
        }
        aux->prox = nNodo;
        return SUCESSO;
    }
}
int excluiDoFim(ListaSE *lista, Dados *dados)
{
    Nodo *nNodo, *antNodo;

    nNodo = lista->inicio;

    if (estaVazia(lista))
    {
        return LISTA_VAZIA;
    }
    while (nNodo->prox != NULL)
    {
        antNodo = nNodo;
        nNodo = nNodo->prox;
    }
    if (nNodo == lista->inicio)
    {
        *dados = lista->inicio->info;
        lista->inicio = nNodo->prox;
    }
    else
    {
        *dados = antNodo->prox->info;
        antNodo->prox = nNodo->prox;
    }
    free(nNodo);
    return SUCESSO;
}
int incluiDepois(ListaSE *lista, Dados dados, int cod)
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
    return SUCESSO;
}
int excluiNodo(ListaSE *lista, Dados *dados, int cod)
{
    Nodo *nNodo, *aux;
    nNodo = lista->inicio;
    if (estaVazia(lista))
    {
        return LISTA_VAZIA;
    }
    while (nNodo != NULL && nNodo->info.cod != cod)
    {
        aux = nNodo;
        nNodo = nNodo->prox;
    }
    if (nNodo == NULL)
    {
        return CODIGO_INEXISTENTE;
    }
    if (nNodo == lista->inicio)
    {
        *dados = lista->inicio->info;
        lista->inicio = nNodo->prox;
    }
    else
    {
        *dados = aux->prox->info;
        aux->prox = nNodo->prox;
    }
    free(nNodo);
    return SUCESSO;
}
int consultaPorCodigo(ListaSE *lista, Dados *dados, int consultaCod)
{
    Nodo *nNodo;
    nNodo = lista->inicio;
    while (nNodo != NULL)
    {
        if (nNodo->info.cod == consultaCod)
        {
            *dados = nNodo->info;
            return SUCESSO;
        }
        nNodo = nNodo->prox;
    }
    return CODIGO_INEXISTENTE;
}
