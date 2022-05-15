#include "pilhaSE.h"
#include <stdio.h>

int main(void)
{
    PilhaSE pilha;
    Dados dados;

    int opcao;

    criaPilha(&pilha);

    do
    {
        puts("\n========= MENU =========");
        puts("1.empilha");
        puts("2.desempilha");
        puts("3.quantidade de nodos");
        puts("4.exibe situacao da pilha");
        puts("5.consulta topo");
        puts("0.fim");

        printf("\ninforme a operacao: ");
        scanf("%d", &opcao);

        switch (opcao)
        {
        case 1:
            printf("\ninforme o codigo(decimal): ");
            scanf("%d", &dados.cod);

            printf("informe o peso: ");
            scanf("%f", &dados.peso);

            if (empilha(&pilha, dados) == FALTOU_MEMORIA)
            {
                puts("\nERRO: FALTOU MEMORIA!\n");
            }
            else
            {
                puts("\ndados incluidos com SUCESSO!\n");
            }
            break;
        case 2:
            if (desempilha(&pilha, &dados) == PILHA_VAZIA)
            {
                puts("\nERRO: PILHA VAZIA!\n");
            }
            else
            {
                puts("--------------------------");
                printf("Pilha:\ncodigo: %d e peso %.2f\n\nexcluidos com SUCESSO!!\n", dados.cod, dados.peso);
                puts("--------------------------");
            }
            break;
        case 3:
            printf("\nquantidade de nodos na pilha: %d\n\n", quantidadeDeNodos(pilha));
            break;
        case 4:
            if (pilhaVazia(&pilha) == 1)
            {
                puts("\na pilha esta vazia\n");
            }
            else
            {
                puts("\na pilha possui 1 ou mais nodos\n");
            }
            break;
        case 5:
            if (consultaTopo(&pilha, dados) == PILHA_VAZIA)
            {
                puts("-----------------------------");
                puts("\nERRO: a pilha esta VAZIA\n");
            }
            else
            {                
                puts("-----------------------------------------------------");
                printf("dados do topo da pilha: cod: %d  peso: %.2f\n\n", dados.cod, dados.peso);
            }
            break;
        }         
        exibe(pilha);
    } while (opcao != 0);
    return 0;
}