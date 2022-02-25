#include <stdio.h>

/*
Defina o tipo CONTA para armazenar o numero de uma conta e seu respectivo saldo.
Escreva um programa para controlar a conta corrente e a conta poupança do sr.Silva. As contas são integradas de forma que quando não houver saldo suficiente na conta corrente uma transferência automática da conta poupança cobrirá um evental saldo (o valor da transferência deve ser igual ao valor necessário para cobrir o saldo negativo).
O programa deve ler o número e o saldo inicial da conta corrente e da poupança criando duas variáveis do tipo Conta (cada uma representa uma conta). A seguir ler uma quantidade indeterminada de duplas de dados representando respectivamente o código da operação
(1.Depósito conta corrente
2.Depósito conta poupança
3.Retirada conta corrente
4.Retirada conta poupança
5.Fim) e o valor do movimento.
O programa termina ao ser informado um código igual a 5 (nesta situação o valor do movimento não deve ser lido).
*/

// Defina o tipo CONTA para armazenar o numero de uma conta e seu respectivo saldo.
typedef struct conta
{
    int num_conta;
    float saldo;
} Conta;

void criaConta(Conta *conta, int num);
void depositaNaConta(Conta *conta, float valor);
float obtemSaldo(Conta *conta);
void retiraDaConta(Conta *conta, float valor);

int main(void)
{
    Conta cc, cp;  
    int num_cc, num_cp, opcao;
    float valor;

    printf("\ninforme numero conta corrente:\n");
    scanf("%d", &num_cc);

    criaConta(&cc, num_cc); // chama a funcao criaconta

    printf("\ninforme numero conta poupanca:\n");
    scanf("%d", &num_cp);

    criaConta(&cp, num_cp); // chama a funcao criaconta    

    while (opcao != 5)
    {
        printf("\nescolha uma opcao:\n");
        printf(" 1-deposito conta corrente\n 2-deposito conta poupanca\n 3-retirada conta corrente\n 4-retirada conta poupanca\n 5-fim\n\n");
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
            printf("sair\n");
            break;

        default:
            printf("opcao invalida\n");
            break;
        }
    }

    return 0;
}
// Entrada: Número da conta
// Saida: Uma conta
// Descrição: Atribui os valores iniciais. O saldo deve ser zerado
void criaConta(Conta *conta, int num)
{
    conta->num_conta = num;
    conta->saldo = 0;
}
void depositaNaConta(Conta *conta, float valor)
{
    conta->saldo += valor;
}
float obtemSaldo(Conta *conta)
{
    return conta->saldo;
}
void retiraDaConta(Conta *conta, float valor)
{
    conta->saldo -= valor;
}