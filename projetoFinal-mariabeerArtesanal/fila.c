#include "fila.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

/*======================== IMPLEMENTACAO DAS FUNCOES ================= */

// FUNCAO ALOCA FILA
void criarFila(FilaProducao *filaLote)
{
    Nodo *criaFila = (Nodo *)malloc(sizeof(Nodo));

    if (criaFila == NULL)
    {
        printf("Erro de Alocacao de Memoria");
    }
    else
    {
        filaLote->inicio = NULL;
        filaLote->fim = NULL;
        filaLote->tam = 0;
    }
}
// FUNCAO VERIFICA SE A FILA ESTA VAZIA
int filaVazia(FilaProducao *filaLote)
{
    if (filaLote->inicio == NULL)
    {
        return FILA_VAZIA;
    }
    else
    {
        return SUCESSO;
    }
}
// // FUNCAO INSERE LOTE NA FILA DE PRODUCAO
int inserir(Beer info, Lote dados, FilaProducao *filaLote)
{
    Nodo *pNodo = (Nodo *)malloc(sizeof(Nodo));

    pNodo->info = info;
    pNodo->dados = dados;
    
    if (pNodo == NULL)
    {
        printf("Erro de Alocacao de memoria");
        return 0;
    }
    else
    {
        if (filaVazia(filaLote))
        {
            filaLote->inicio = pNodo;
        }
        else
        {
            filaLote->fim->prox = pNodo;
        }
        filaLote->fim = pNodo;
        filaLote->tam++;

        return SUCESSO;
    }
}
// // FUNCAO LIBERA LOTE
int retirar(Beer *info, Lote *dados, FilaProducao *filaLote)
{
    Nodo *pNodo;
    if (filaVazia(filaLote))
    {
        return FILA_VAZIA;
    }
    else
    {
        *info = filaLote->inicio->info;
        *dados = filaLote->inicio->dados;

        pNodo = filaLote->inicio;      
        filaLote->inicio = pNodo->prox;
        
        filaLote->tam--;
        free(pNodo);
        return SUCESSO;
    }
}
// // FUNCAO EXIBE LOTES INSERIDOS NA FILA
void exibeFila(FilaProducao filaLote)
{
    Nodo *pAux;
    pAux = filaLote.inicio;

    printf("--------------------------- PRODUCAO MARIABEER- CERVEJA ARTESANAL -------------------------\n");
    puts("-------------------------------------------------------------------------------------------");
    printf(" [LOTE]  [FABRICACAO] [VALIDADE]  [MARCA]    [ESTILO]  [EMBALAGEM]  [VOLUME] [UNIDADES]\n");
    while (pAux != NULL)
    {
        printf(" %3d  %5d/%d/%d %10d %10s %10s %10s %10d %10d\n",
               pAux->dados.lote,
               pAux->dados.dia, pAux->dados.mes, pAux->dados.ano,
               pAux->dados.val,
               pAux->info.marca,
               pAux->info.estilo,
               pAux->info.embalagem,
               pAux->info.volume,
               pAux->info.unid);

        pAux = pAux->prox;
    }
    puts("-------------------------------------------------------------------------------------------");
    printf("Lotes aguardando liberacao = %d\n", filaLote.tam);
}
// FUNCAO MENU PRINCIPAL
int quantidadeDeNodos(FilaProducao filaLote)
{
    return filaLote.tam;
}
// FUNCAO RETORNA AS INFORMACOES DO 1 LOTE DA FILA
int consultaInicio(Lote *dados, Beer *info, FilaProducao *filaLote)
{
    Nodo *pAux;
    if (filaVazia(filaLote))
    {
        return FILA_VAZIA;
    }
    else
    {
        pAux = filaLote->inicio;
        *dados = filaLote->inicio->dados;
        *info = filaLote->inicio->info;
        return SUCESSO;
    }
}
// FUNCAO CONSULTA SE O LOTE CONSTA NA FILA
int consultaPorCodigo(Lote *dados, Beer *info, int cod, FilaProducao *filaLote)
{
    Nodo *pAux;
    pAux = filaLote->inicio;
    while (pAux != NULL)
    {
        if (pAux->dados.lote == cod)
        {
            *info = pAux->info;
            *dados = pAux->dados;         
            return SUCESSO;
        }
        pAux = pAux->prox;
    }
    return CODIGO_INEXISTENTE;
}
// FUNCAO CRIA MENU
int menuPrincipal()
{
    int menuPrincipal;

    printf("\n========= MARIABEER =========\n");
    puts("1. Adicionar lote na fila");
    puts("2. Exibir fila de lotes em espera");
    puts("3. Liberar lote");
    puts("4. Numero de lotes aguardando liberacao");
    puts("5. Consultar 1o lote da fila");
    puts("6. Consultar por codigo");
    puts("7. SAIR");

    printf("\nInforme a operacao: ");
    scanf("%d", &menuPrincipal);

    return menuPrincipal;
}

