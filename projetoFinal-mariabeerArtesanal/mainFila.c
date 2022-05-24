#include "fila.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// FUNCAO PRINCIPAL
int main(void)
{
    int opcao, subOp, cod, op;

    Beer info;
    Lote dados;
    FilaProducao filaLote;

    criarFila(&filaLote);

    do
    {
        opcao = menuPrincipal();
        system("clear");

        switch (opcao)
        {
        case 1:
            do
            {
                printf("============= DESCRICAO DO LOTE =================\n");
                printf("Lote de fabricacao: ");
                scanf("%d", &dados.lote);
                printf("Data de fabricacao(dia/mes/ano): ");
                scanf("%d %d %d", &dados.dia, &dados.mes, &dados.ano);
                printf("Validade: ");
                scanf("%d", &dados.val);
                printf("Marca: ");
                setbuf(stdin, 0);
                fgets(info.marca, 255, stdin);
                info.marca[strlen(info.marca) - 1] = '\0';
                printf("Estilo de Cerveja: ");
                setbuf(stdin, 0);
                fgets(info.estilo, 255, stdin);
                info.estilo[strlen(info.estilo) - 1] = '\0';
                printf("Embalagem: ");
                setbuf(stdin, 0);
                fgets(info.embalagem, 255, stdin);
                info.embalagem[strlen(info.embalagem) - 1] = '\0';
                printf("Volume da unidade(Litros): ");
                scanf("%d", &info.volume);
                printf("Unidades: ");
                scanf("%d", &info.unid);                

                op = inserir(info, dados, &filaLote) == SUCESSO;
                {
                    puts("\nLote inserido com SUCESSO!\n");
                } 
                exibeFila(filaLote);             
                printf("\n\n0 - Voltar Menu   |   1 - Continuar\n\n");                
                printf("-> ");
                scanf("%d", &subOp);                
                system("clear");
            } while (subOp == 1);
            break;
        case 2:
            exibeFila(filaLote);
            break;
        case 3:
            do
            {
                op = retirar(&info, &dados, &filaLote);
                if (op == FILA_VAZIA)
                {
                    puts("\nERRO: A Fila está VAZIA!!\n");
                    printf("0 - Voltar Menu  \n\n");
                    printf("-> ");
                    scanf("%d", &subOp);
                    system("clear");
                }
                else
                {
                    printf("\nLote %d liberado!!\n\n", dados.lote);
                    exibeFila(filaLote);
                    printf("\n\n0 - Voltar Menu   |   1 - Continuar\n\n");                   
                    printf("-> ");
                    scanf("%d", &subOp);
                    system("clear");
                }
            } while (subOp == 1);
            break;
        case 4:
            printf("\nNumero de lotes aguardando liberacao: %d\n\n", quantidadeDeNodos(filaLote));
            break;
        case 5:
            if (consultaInicio(&dados, &info, &filaLote) == FILA_VAZIA)
            {
                puts("-------------------------------------------");
                puts("\nERRO: a fila esta VAZIA\n");
            }
            else
            {
                puts("-----------------------------");
                printf("\nID lote: %d \nFabricacao: %d/%d/%d\nEstilo: %s \n\n", dados.lote, dados.dia, dados.mes, dados.ano, info.estilo);
                printf("------------------------------");
            }
            break;
        case 6:
            do
            {
                printf("informe o codigo do lote: ");
                scanf("%d", &cod);

                if (consultaPorCodigo(&dados, &info, cod, &filaLote) == CODIGO_INEXISTENTE)
                {
                    puts("\nERRO: Codigo Inexistente\n");
                }
                else
                {
                    puts("-------------------------------------------");
                    printf("\nID lote: %d \nFabricacao: %d/%d/%d\nEstilo: %s\n\n", dados.lote, dados.dia, dados.mes, dados.ano, info.estilo);
                }
                printf("0 - Voltar Menu   |   1 - Continuar\n\n");
                printf("-> ");
                scanf("%d", &subOp);
                system("clear");

            } while (subOp == 1);
            break;            
        }        
    } while (opcao != 7);
    return 0;
}