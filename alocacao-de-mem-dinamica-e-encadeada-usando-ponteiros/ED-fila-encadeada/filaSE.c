#include "filaSE.h"
#include <stdio.h>
#include <stdlib.h>

void criaFila(FilaSE *fila)
{
    fila->inicio = NULL;
    fila->fim = NULL;
}
int insere(FilaSE *fila, Dados dados)
{
    Nodo *nNodo;
    nNodo = (Nodo *)malloc(sizeof(Nodo));
    if (nNodo == NULL) 
    {
        return FALTOU_MEMORIA;
    }
    nNodo->info = dados;
    nNodo->prox = NULL;
    if (fila->inicio == NULL) 
    {
        fila->inicio = nNodo;
    }
    else 
    {
        fila->fim->prox = nNodo; 
    }
    fila->fim = nNodo; 
    return SUCESSO;
}

void exibe(FilaSE fila)
{
    Nodo *pAux;
    pAux = fila.inicio;
    puts("---------------------------------------------------");
    printf("[EnderecoInicio]\n %p \n", fila.inicio);
    printf("Exibindo a FILA ENCADEADA:\n");
    printf("[EnderecoNodo]       [cod] [peso] [EnderecoProxNodo]\n");
    while (pAux != NULL)
    {
        printf("  %p -   %3d  %.2f - %p\n", pAux, pAux->info.cod, pAux->info.peso, pAux->prox);       
        pAux = pAux->prox;
    }
}
int estaVazia(FilaSE *fila)
{
    if (fila->inicio == NULL)
    {
        return FILA_VAZIA;
    }
    else
    {
        return SUCESSO;
    }
}
int retira(FilaSE *fila, Dados *dados)
{
    Nodo *nNodo;
    if (estaVazia(fila))
    {
        return FILA_VAZIA;
    }
    else
    {
        *dados = fila->inicio->info;
        nNodo = fila->inicio;
        fila->inicio = fila->inicio->prox;
        free(nNodo);
        return SUCESSO;
    }
}
int quantidadeDeNodos(FilaSE fila)
{
    Nodo *pAux;
    int cont = 0;

    pAux = fila.inicio;
    while (pAux != NULL)
    {
        cont++;
        pAux = pAux->prox;
    }
    return (cont);
}
int consultaInicio(FilaSE *fila, Dados *dados)
{
    Nodo *nNodo;
    if (estaVazia(fila))
    {
        return FILA_VAZIA;
    }
    else
    {
        nNodo = fila->inicio;
        *dados = nNodo->info;
        return SUCESSO;
    }
}