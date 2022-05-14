#include "listaSE.h"
#include <stdio.h>
#include <stdlib.h>

int main(void)
{
    ListaSE lista;
    Dados dados;
    int opcao, consultaCod, cod, op;

    criaLista(&lista);

    opcao = 1;
    while (opcao != 0)
    {
        puts("\n========= MENU =========");
        puts("1-inclui no inicio");
        puts("2-exibe lista");
        puts("3-quantidade de nodos");
        puts("4-exibe situacao da lista");
        puts("5-exclui do inicio");
        puts("6-inclui no fim");
        puts("7-exclui do fim");
        puts("8-consulta por codigo");
        puts("9-inclui depois");
        puts("10-exclui nodo");
        puts("0-fim");

        printf("\ninforme a operacao: ");
        scanf("%d", &opcao);
        system("clear");

        switch (opcao)
        {
        case 1:
            printf("informe o codigo(decimal): ");
            scanf("%d", &dados.cod);

            printf("informe o peso: ");
            scanf("%f", &dados.peso);

            if (incluiNoInicio(&lista, dados) == FALTOU_MEMORIA)
            {
                puts("\nERRO: FALTOU MEMORIA!\n");
            }
            else
            {
                puts("\ndados incluidos com SUCESSO!\n");
            }
            break;
        case 2:
            exibe(lista);
            break;
        case 3:
            printf("\nquantidade de nodos na lista: %d\n\n", quantidadeDeNodos(lista));
            break;
        case 4:
            if (estaVazia(&lista) == 1)
            {
                puts("\na lista esta vazia\n");
            }
            else
            {
                puts("\na lista possui 1 ou mais nodos\n");
            }
            break;
        case 5:
            if (excluiDoInicio(&lista, &dados) == LISTA_VAZIA)
            {
                puts("\nERRO: LISTA VAZIA!\n");
            }
            else
            {
                puts("--------------------------");
                printf("Lista:\ncodigo: %d e peso %.2f\n\nexcluidos com SUCESSO!!\n", dados.cod, dados.peso);
                puts("--------------------------");
            }
            break;
        case 6:
            printf("informe o codigo(decimal): ");
            scanf("%d", &dados.cod);

            printf("informe o peso: ");
            scanf("%f", &dados.peso);

            if (incluiNoFim(&lista, dados) == FALTOU_MEMORIA)
            {
                puts("\nERRO: FALTOU MEMORIA!\n");
            }
            else
            {
                puts("\ndados incluidos com SUCESSO!\n");
            }
            break;
        case 7:
            if (excluiDoFim(&lista, &dados) == LISTA_VAZIA)
            {
                puts("\nERRO: a lista esta VAZIA\n");
            }
            else
            {
                puts("--------------------------");
                printf("Lista:\ncodigo: %d e peso %.2f\n\nexcluidos com SUCESSO!!\n", dados.cod, dados.peso);
                puts("--------------------------");
            }
            break;
        case 8:
            printf("informe o codigo: ");
            scanf("%d", &consultaCod);

            if (consultaPorCodigo(&lista, &dados, consultaCod) == CODIGO_INEXISTENTE)
            {
                puts("---------------------------");
                puts("ERRO: Codigo informado eh inexistente\n");
            }
            else
            {
                puts("---------------------------");
                puts("Codigo encontrado");
                printf("codigo: %d | peso: %.2f\n", dados.cod, dados.peso);
            }
            break;
        case 9:
            printf("informe o codigo para consulta: ");
            scanf("%d", &cod);

            printf("informe o codigo que sera inserido: ");
            scanf("%d", &dados.cod);
            printf("informe o peso que sera inserido: ");
            scanf("%f", &dados.peso);

            op = incluiDepois(&lista, dados, cod);
            if (op == FALTOU_MEMORIA)
            {
                puts("---------------------------");
                puts("\nERRO: faltou MEMORIA");
            }
            else if (op == LISTA_VAZIA)
            {
                puts("\nERRO: a lista esta VAZIA\n");
            }
            else if (op == CODIGO_INEXISTENTE)
            {
                puts("---------------------------");
                puts("\nERRO: codigo informado eh INEXISTENTE. nao foi possivel inserir os dados!!\n");
            }
            else
            {
                puts("\ndados incluidos com SUCESSO!");
            }
            break;
        case 10:
            printf("informe o codigo dos dados para exclusao: ");
            scanf("%d", &cod);
            op = excluiNodo(&lista, &dados, cod);
            if (op == LISTA_VAZIA)
            {
                puts("---------------------------");
                puts("ERRO: a lista esta VAZIA\n");
            }
            else if (op == CODIGO_INEXISTENTE)
            {
                puts("---------------------------");
                puts("ERRO: codigo inexistente\n");
            }
            else
            {
                puts("---------------------------");
                printf("codigo: %d peso: %.2f\ndados excluidos com SUCESSO!\n", dados.cod, dados.peso);
            }
            break;
        } // fim switch case
        if (opcao != 2)
        {
            exibe(lista);
        }
    } // fim while
    return 0;
}