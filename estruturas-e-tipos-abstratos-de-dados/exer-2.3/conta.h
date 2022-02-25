#ifndef CONTA_H_INCLUDED
#define CONTA_H_INCLUDED

typedef struct conta
{
    int num_conta;
    float saldo;
} Conta;

void criaConta(Conta *conta, int num);
void depositaNaConta(Conta *conta, float valor);
float obtemSaldo(Conta *conta);
void retiraDaConta(Conta *conta, float valor);

#endif // CONTA_H_INCLUDED
