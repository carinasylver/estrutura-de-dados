#include "filaSE.h"
#include <stdio.h>


int main(void)
{
    FilaSE fila;
    Dados dados;
    int opcao;

    criaFila(&fila);
    do
    {
        puts("\n========= MENU =========");
        puts("1.insere na fila");
        puts("2.retira da fila");
        puts("3.quantidade de nodos");
        puts("4.exibe situacao da fila");
        puts("5.consulta inicio da fila");
        puts("0.fim");

        printf("\ninforme a operacao: ");
        scanf("%d", &opcao);
        system("clear");

        switch (opcao)
        {
        case 1:
            printf("\ninforme o codigo(decimal): ");
            scanf("%d", &dados.cod);

            printf("informe o peso: ");
            scanf("%f", &dados.peso);

            if (insere(&fila, dados) == FALTOU_MEMORIA)
            {
                puts("\nERRO: FALTOU MEMORIA!\n");
            }
            else
            {
                puts("----------------------------------");
                puts("\ndados incluidos com SUCESSO!\n");
            }
            break;
        case 2:

            if (retira(&fila, &dados) == FILA_VAZIA)
            {
                puts("----------------------------");
                printf("\nERRO: a Fila esta VAZIA!\n\n");
            }
            else
            {
                puts("--------------------------------");
                printf("\ncodigo: %d | peso %.2f\n\nremovidos da fila com SUCESSO!\n\n", dados.cod, dados.peso);
            }
            break;
        case 3:
         puts("-------------------------------");
            printf("\nquantidade de nodos na Fila: %d\n\n", quantidadeDeNodos(fila));
            break;
        case 4:
            if (estaVazia(&fila) == 1)
            {
                puts("------------------------");
                puts("\na fila esta VAZIA\n");
            }
            else
            {
                puts("-----------------------------------");
                puts("\na fila possui 1 ou mais nodos\n");
            }
            break;
        case 5:
            if (consultaInicio(&fila, &dados) == FILA_VAZIA)
            {
                puts("------------------------------");
                puts("\nERRO: a fila esta VAZIA\n");
            }
            else
            {
                puts("--------------------------------------------------");
                printf("\ndados do inicio da fila: cod: %d  peso: %.2f\n\n", dados.cod, dados.peso);
            }
            break;
        } // fim do switch case
        // Após a execução de cada operação deve ser exibida a pilha através da operação exibe.
        exibe(fila);

    } while (opcao != 0);
    // enquanto for diferente da opcao 0 execute

    return 0;
}