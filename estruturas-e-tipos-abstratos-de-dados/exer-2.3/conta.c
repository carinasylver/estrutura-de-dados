#include "conta.h"

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