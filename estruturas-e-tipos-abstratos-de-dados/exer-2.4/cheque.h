#ifndef CHEQUE_H_INCLUDED
#define CHEQUE_H_INCLUDED

typedef struct cheque
{
    int num, situacao;
    float valor;
} Cheque;

void criaCheque(int num, Cheque *cheque);
void exibeCheque(Cheque cheque);
int obtemSituacao(Cheque cheque);
float obtemValor(Cheque cheque);
int obtemNumero(Cheque cheque);
int compensaCheque(Cheque *cheque);
int emiteCheque(Cheque *cheque, float valor);

#endif // CHEQUE_H_INCLUDED