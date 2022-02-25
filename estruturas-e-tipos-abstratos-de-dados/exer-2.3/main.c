#include <stdio.h>
#include "conta.c"

int main(void)
{
    Conta cc, cp;
    int num_cc, num_cp, opcao;
    float valor;

    printf("\ninforme numero conta corrente:\n");
    scanf("%d", &num_cc);

    criaConta(&cc, num_cc);

    printf("\ninforme numero conta poupanca:\n");
    scanf("%d", &num_cp);

    criaConta(&cp, num_cp);

    while (opcao != 5)
    {
        printf("\nescolha uma opcao:\n");
        printf(" 1-deposito conta corrente\n 2-deposito conta poupanca\n 3-retirada conta corrente\n 4-retirada conta poupanca\n 5-Fim\n\n");
        scanf("%d", &opcao);

        switch (opcao)
        {
        case 1:
            printf("\ndeposito conta corrente\n");
            printf("digite o valor:\n");
            scanf("%f", &valor);
            depositaNaConta(&cc, valor);
            printf("saldo atual: R$ %.2f\n", obtemSaldo(&cc));
            break;
        case 2:
            printf("\ndeposito conta poupanca\n");
            printf("digite o valor:\n");
            scanf("%f", &valor);
            depositaNaConta(&cp, valor);
            printf("saldo atual: R$ %.2f\n", obtemSaldo(&cc));
            break;
        case 3:
            printf("retirada conta corrente\n");
            printf("digite o valor:\n");
            scanf("%f", &valor);
            if (obtemSaldo(&cc) >= valor)
            {
                retiraDaConta(&cc, valor);
            }
            else if (obtemSaldo(&cp) >= valor)
            {
                retiraDaConta(&cp, valor);
            }
            else
            {
                printf("saldo insuficiente");
            }
            break;
        case 4:
            printf("retirada conta poupanca\n");
            printf("digite o valor:\n");
            scanf("%f", &valor);
            if (obtemSaldo(&cp) >= valor)
            {
                retiraDaConta(&cp, valor);
            }
            else
            {
                printf("saldo insuficiente");
            }
            break;
        case 5:
            printf("sair.\n");
            break;

        default:
            printf("opcao invalida\n");
            break;
        }
    }

    return 0;
}