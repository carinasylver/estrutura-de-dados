#include <stdio.h>
#include "cheque.c"

int main(void)
{
    Cheque cheq1, cheq2;
    int num;
    float valor, valor2;
    
    printf("digite o numero do 1o cheque: ");
    scanf("%d", &num);

    criaCheque(num, &cheq1);

    printf("digite o numero do 2o cheque: ");
    scanf("%d", &num);

    criaCheque(num, &cheq2);

    printf("\ndigite o valor do 1o cheque:");
    scanf("%f", &valor);

    emiteCheque(&cheq1, valor);

    printf("digite o valor do 2o cheque: ");
    scanf("%f", &valor);
    printf("\n=============================================\n");

    emiteCheque(&cheq2, valor);

    exibeCheque(cheq1);
    exibeCheque(cheq2);

    valor = obtemValor(cheq1);
    valor2 = obtemValor(cheq2);
    if (valor > valor2)
    {
        compensaCheque(&cheq1);
    }
    else
    {
        compensaCheque(&cheq2);
    }

    printf("situacao do 1o cheque: %d\n", obtemSituacao(cheq1));
    printf("situacao do 2o cheque: %d\n", obtemSituacao(cheq2));
    printf("Numero do 1o  cheque: %d\n", obtemNumero(cheq1));
    printf("Numero do 2o cheque: %d\n", obtemNumero(cheq2));

    return 0;
}