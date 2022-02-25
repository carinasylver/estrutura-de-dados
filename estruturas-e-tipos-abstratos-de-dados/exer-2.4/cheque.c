#include <stdio.h>
#include "cheque.h"

void criaCheque(int num, Cheque *cheque)
{
    cheque->num = num;
    cheque->situacao = 0;
    cheque->valor = 0;
}
void exibeCheque(Cheque cheque)
{

    printf("numero:%2d  saldo:%f  situacao: ", cheque.num, cheque.valor);
    if (cheque.situacao == 0)
    {
        printf("em branco\n");
    }
    else if (cheque.situacao == 1)
    {
        printf("emitido\n");
    }
    else
    {
        printf("compensado\n");
    }
}
int obtemSituacao(Cheque cheque)
{
    return cheque.situacao;
}
float obtemValor(Cheque cheque)
{
    return cheque.valor;
}
int obtemNumero(Cheque cheque)
{
    return cheque.num;
}
int compensaCheque(Cheque *cheque)
{
    if (cheque->situacao == 1)
    {
        cheque->situacao = 2;
        return 0;
    }
    else
    {
        return 1;
    }
}
int emiteCheque(Cheque *cheque, float valor)
{
    if (cheque->situacao == 0)
    {
        cheque->valor = valor;
        cheque->situacao = 1;
        return 0;
    }
    else
    {
        return 1;
    }
}
