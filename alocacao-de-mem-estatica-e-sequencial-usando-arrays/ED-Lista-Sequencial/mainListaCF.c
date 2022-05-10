#include "listaCF.h"
#include <stdio.h>

int main(void)
{
    ListaCF lista;
    Dados dado;
    int opcao, cod, consultaCod, pesqCod;

    criaLista(&lista);

    opcao = 1;
    while (opcao != 0)
    {
        puts("\n========= MENU =========");
        puts("1-inclui no fim");
        puts("2-exibe lista");
        puts("3-quantidade de nodos");
        puts("4-exibe situacao da lista");
        puts("5-exclui do fim");
        puts("6-inclui no inicio");
        puts("7-exclui do inicio");
        puts("8-consulta por codigo");
        puts("9-inclui antes");
        puts("10-exclui nodo");
        puts("0-fim");

        printf("\ninforme a operacao: ");
        scanf("%d", &opcao);
        system("clear");

        switch (opcao)
        {
        case 1:
            printf("informe o codigo(decimal): ");
            scanf("%d", &dado.cod);

            printf("informe o peso: ");
            scanf("%f", &dado.peso);
            system("clear");

            if (incluiNoFim(&lista, dado) == LISTA_CHEIA)
            {
                printf("\nERRO: a lista esta cheia!\n"); // quando lista->n == 5
            }
            else
            {
                printf("\ncod: %d | peso: %.2f\nincluidos com SUCESSO na ultima posicao da lista!\n", dado.cod, dado.peso);
            }
            break;
        case 2:
            exibe(&lista);
            break;
        case 3:
            printf("\nquantidade de nodos na lista: %d\n\n", quantidadeDeNodos(&lista));
            break;
        case 4:
            if (estaCheia(&lista) == 1)
            {
                puts("\nERRO: lista CHEIA!\n");
            }
            else if (estaVazia(&lista) == 1)
            {
                puts("\na lista esta VAZIA\n");
            }
            else
            {
                puts("\nainda ha espaco na lista\n");
            }
            break;
        case 5:
            if (excluiDoFim(&lista, &dado) == LISTA_VAZIA)
            {
                puts("\nERRO: a lista esta VAZIA\n");
            }
            else
            {
                printf("\ncod: %d | peso: %.2f\nexcluidos com SUCESSO!\n", dado.cod, dado.peso);
            }
            break;
        case 6:
            printf("\ninforme o codigo: ");
            scanf("%d", &dado.cod);

            printf("informe o peso: ");
            scanf("%f", &dado.peso);

            if (incluiNoInicio(&lista, dado) == LISTA_CHEIA)
            {
                printf("\nERRO: a lista esta cheia\n");
            }
            else
            {
                printf("\ncod: %d | peso: %.2f\nincluidos com SUCESSO na 1a posicao da lista!\n", dado.cod, dado.peso);
            }
            break;
        case 7:
            if (excluiDoInicio(&lista, &dado) == LISTA_VAZIA)
            {
                printf("ERRO: A lista esta vazia\n");
            }
            else
            {
                printf("\ncod: %d | peso: %.2f\nexcluidos com SUCESSO!\n", dado.cod, dado.peso);
            }
            break;
        case 8:
            printf("informe o codigo: ");
            scanf("%d", &consultaCod);

            if (consultaPorCodigo(&lista, &dado, consultaCod) == CODIGO_INEXISTENTE)
            {
                puts("\nERRO: Codigo inexistente\n");
            }
            else
            {
                puts("---------------------------");
                printf("\ncodigo: %d peso: %.2f\n", dado.cod, dado.peso);
            }
            break;
        case 9:
            printf("informe o codigo: ");
            scanf("%d", &dado.cod);
            printf("informe o peso: ");
            scanf("%f", &dado.peso);
            printf("informe o codigo para consulta: ");
            scanf("%d", &cod);

            pesqCod = incluiAntes(&lista, dado, cod);
            if (pesqCod == LISTA_CHEIA)
            {
                puts("\nERRO: a lista esta cheia");
            }
            else if (pesqCod == CODIGO_INEXISTENTE)
            {
                puts("\nERRO: codigo inexistente\n");
            }
            else
            {
                puts("\ndados incluidos com SUCESSO!");
            }
            break;

        case 10:
            printf("informe o codigo dos dados para exclusao: ");
            scanf("%d", &consultaCod);

            pesqCod = excluiNodo(&lista, consultaCod);
            if (pesqCod == LISTA_VAZIA)
            {
                puts("\nERRO: a lista esta VAZIA");
            }
            else if (pesqCod == CODIGO_INEXISTENTE)
            {
                puts("\nERRO: codigo inexistente\n");
            }
            else
            {
                printf("\ncod: %d | peso: %.2f\nexcluidos com SUCESSO!\n", dado.cod, dado.peso);
            }
            break;
        }
        if(opcao != 2)
        {
            exibe(&lista);
        }
    } 

    return 0;
}