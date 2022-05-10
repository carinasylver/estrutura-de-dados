/*--------------------------------
* TIPOS DE DADOS LISTA E IMPLEMENTACAO DAS FUNCOES
----------------------------------*/
#include <stdio.h>
#include "listaCF.h"

void criaLista(ListaCF *lista)
{
    lista->n = 0;
}
int incluiNoFim(ListaCF *lista, Dados dado)
{
    if (estaCheia(lista))
        return LISTA_CHEIA;
    else
    {
        lista->v[lista->n] = dado;
        lista->n++;
        return SUCESSO;
    }
}
void exibe(ListaCF *lista)
{
    puts("--------------------------");
    puts("Lista:");
    for (int i = 0; i < lista->n; i++)
    {

        printf("\ncodigo: %d | peso: %.2f\n", lista->v[i].cod, lista->v[i].peso);
        puts("--------------------------");
    }
}
int quantidadeDeNodos(ListaCF *lista)
{
    return lista->n;
}
int estaCheia(ListaCF *lista)
{

    if (lista->n == MAX_NODOS)
    {
        return 1; // lista cheia
    }
    else
    {
        return 0;
    }
}
int estaVazia(ListaCF *lista)
{
    if (lista->n <= 0)
    {
        return 1;
    }
    else
    {
        return 0;
    }
}
int excluiDoFim(ListaCF *lista, Dados *dado)
{
    if (estaVazia(lista))
    {
        return LISTA_VAZIA;
    }
    else
    {
        *dado = lista->v[lista->n - 1];
        lista->n--;
        return SUCESSO;
    }
}
int incluiNoInicio(ListaCF *lista, Dados dado)
{

    if (estaCheia(lista))
    {
        return LISTA_CHEIA;
    }
    else
    {
        for (int i = lista->n - 1; i >= 0; i--)
        {
            lista->v[i + 1] = lista->v[i];
        }
        lista->v[0] = dado;
        lista->n++;

        return SUCESSO;
    }
}
int excluiDoInicio(ListaCF *lista, Dados *dado)
{
    if (estaVazia(lista))
    {
        return LISTA_VAZIA;
    }
    else
    {
        *dado = lista->v[0];
        for (int i = 0; i < lista->n - 1; i++) 
        {
            lista->v[i] = lista->v[i + 1];            
        }
        lista->n--;
        return SUCESSO;
    }
}
int consultaPorCodigo(ListaCF *lista, Dados *dado, int consultaCod)
{
    int k, i = 0;

    while (i < lista->n && lista->v[i].cod != consultaCod)
        i++;
    if (i == lista->n) 
        return CODIGO_INEXISTENTE;

    *dado = lista->v[i];
    return SUCESSO;
}
int incluiAntes(ListaCF *lista, Dados dado, int cod)
{
    int i = 0;
    if (estaCheia(lista)) 
    {
        return LISTA_CHEIA;
    }
    else
    {
        while (i < lista->n && lista->v[i].cod != cod)
            i++;
        if (i == lista->n) 
        {
            return CODIGO_INEXISTENTE;
        } 
        else
        {
            for (int i = lista->n - 1; i >= 0; i--)
            {
                lista->v[i + 1] = lista->v[i]; 
            }
            lista->v[i] = dado; 
            lista->n++;
            return SUCESSO;
        }
    }
}
int excluiNodo(ListaCF *lista, int consultaCod) 
{
    int k, i = 0;

    if (estaVazia(lista))
    {
        return LISTA_VAZIA;
    }
    while (i < lista->n && lista->v[i].cod != consultaCod)
        i++;
    if (i == lista->n) 
        return CODIGO_INEXISTENTE;

    for (k = i; k < lista->n; k++) 
    {                              
        lista->v[k] = lista->v[k + 1];
    }
    lista->n--; 
    return SUCESSO;
}
