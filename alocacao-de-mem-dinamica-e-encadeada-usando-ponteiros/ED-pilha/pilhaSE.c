#include "pilhaSE.h"
#include <stdio.h>
#include <stdlib.h>

void criaPilha(PilhaSE *pilha)
{
    pilha->topo = NULL;
}
int empilha(PilhaSE *pilha, Dados dados)
{
    Nodo *pNodo;
    pNodo = (Nodo *) malloc(sizeof(Nodo));

    if (pNodo == NULL) 
    {
        return FALTOU_MEMORIA; 
    }  
    else
    {
        pNodo->info = dados;  
        pNodo->prox = pilha->topo;
        pilha->topo = pNodo;
        return SUCESSO;
    }
}
int desempilha(PilhaSE *pilha, Dados *dados)
{
    Nodo *pNodo; 

    if (pilhaVazia(pilha))
    {
        return PILHA_VAZIA;
    }
    else
    {     
        *dados = pilha->topo->info;  
        pNodo = pilha->topo; 
        pilha->topo = pilha->topo->prox; 
        free(pNodo);
        return SUCESSO;
    }
}
int quantidadeDeNodos(PilhaSE pilha)
{
    Nodo *pAux;
    int cont = 0;

    pAux = pilha.topo;
    while (pAux != NULL)
    {
        cont++;
        pAux = pAux->prox;
    }
    return (cont);
}
void exibe(PilhaSE pilha)
{
    Nodo *pAux = pilha.topo;
    puts("--------------------------------------------------------");
    printf("[EnderecoInicio] %p \n", pilha.topo);
     puts("--------------------------------------------------------");
    printf("Exibindo a PILHA ENCADEADA:\n");
    printf("[EnderecoNodo]       [cod] [peso] [EnderecoProxNodo]\n");
    while (pAux != NULL)
    {
        printf("  %p -   %3d  %.2f - %p\n", pAux, pAux->info.cod, pAux->info.peso, pAux->prox);
        puts("--------------------------------------------------------");
        pAux = pAux->prox;
    }
    printf("[EnderecoFim]: NULL\n");
    puts("--------------------------------------------------------");
}
int pilhaVazia(PilhaSE *pilha)
{
    if (pilha->topo == NULL)
    {
        return 1;
    }
    else
    {
        return 0;
    }
}
int consultaTopo(PilhaSE *pilha, Dados dados)
{
    Nodo *nNodo;
    if (pilhaVazia(pilha))
    {
        return PILHA_VAZIA;
    }
    else
    {
        nNodo = pilha->topo;
        nNodo->info = dados;
        return SUCESSO;
    }
}
