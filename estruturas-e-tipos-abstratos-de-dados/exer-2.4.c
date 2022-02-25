#include <stdio.h>
/*
Defina o tipo Cheque para armazenar o número, o valor e a situação (0-Em branco,1-Emitido, 2-Compensado)de um cheque.
*criaCheque
Saı́da: um cheque
Entrada: Número do cheque
Descrição:	Atribui os valores iniciais.O valor e a situaçã o do cheque deve ser zeradas.
*exibeCheque
Entrada: Um	cheque
Descrição: Exibe um uma única linha as 3 informações contidasno cheque
*obtemSituacao
Entrada: um cheque
Retorno: O código da situação	do cheque
*obtemValor
Entrada: um	cheque
Retorno: O valor do	cheque
*obtemNumero
Entrada: um	cheque
Retorno: O número do cheque
*compensaCheque
Entrada/Saı́da:	um cheque
Retorno: Código 0(sucesso),1(erro)
Descrição:	Altera a situação do cheque para 2 (compensado).	
O cheque só pode ser compensado se	a situação for igual a 1(emitido)*
*emiteCheque
Entrada/Saı́da:	um cheque
Entrada:	Valor do cheque
Retorno:	Código 0(sucesso), 1(erro)
Descrição:	Atribui um valor ao cheque e altera a situação para o código1(Emitido).O cheque só 	pode ser emitido se	a situação for igual a 0 (em branco)
*Escreva um programa para ler dois números e criar dois cheques armazenando-os em 2 variáveis(usar criaCheque)
*Ler 2valores e emitir os 2 cheques(usar emiteCheque).
*Escrever na tela os dados dos 2cheques(usar exibeCheque)
*Compensar o que possui maior valor(usar obtemValor para obter o valor de cada cheque e compensaCheque para fazer a compensação.
*Escreva somente o código da situação dos 2 cheques(usar obtemSituacao)
*Escreva somente o número dos 2 cheques(usar obtemNumero).

*/

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

int main(void)
{
    Cheque cheq1, cheq2;
    int num;
    float valor, valor2;

    /*Escreva um  programa para	ler	dois números e criar dois cheques armazenando-os em 2 variáveis(usar criaCheque)*/
    printf("digite o numero do 1o cheque: ");
    scanf("%d", &num);

    criaCheque(num, &cheq1); // chama funcao cricheque

    printf("digite o numero do 2o cheque: ");
    scanf("%d", &num);

    criaCheque(num, &cheq2);// chama funcao criacheque

    /*Ler 2 valores e emitir os 2 cheques(usar emiteCheque).*/
    printf("\ndigite o valor do 1o cheque: ");
    scanf("%f", &valor);

    emiteCheque(&cheq1, valor);// chama funcao criacheque

    printf("digite o valor do 2o cheque: ");
    scanf("%f", &valor);
    printf("\n=============================================\n");

    emiteCheque(&cheq2, valor);

    //Escrever na tela os dados dos	2cheques(usar exibeCheque)
    exibeCheque(cheq1);// chama funcao exibeCheque
    exibeCheque(cheq2);// chama funcao exibeCheque

    /*Compensar o que possui maior valor(usar obtemValor para obter o valor de cada cheque e compensaCheque para fazer a compensação.*/
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
    /*Escreva somente o código da situação dos 2 cheques(usar obtemSituacao).*/
    printf("situacao do 1o cheque: %d\n", obtemSituacao(cheq1));
    printf("situacao do 2o cheque: %d\n", obtemSituacao(cheq2));
    /*Escreva somente o número	dos	2 cheques(usar obtemNumero).*/
    printf("Numero do 1o  cheque: %d\n", obtemNumero(cheq1));
    printf("Numero do 2o cheque: %d\n", obtemNumero(cheq2));

    return 0;
}
/*criaCheque
Saı́da: um cheque
Entrada: Número do cheque
Descrição: Atribui	os valores iniciais.O valor e a situação do cheque deve ser zeradas.*/
void criaCheque(int num, Cheque *cheque)
{
    cheque->num = num;
    cheque->situacao = 0;
    cheque->valor = 0;
}
/*
exibeCheque
Entrada: Um cheque
Descrição: Exibe um uma única linha as 3 informações contidasno cheque
*/
void exibeCheque(Cheque cheque)
{
    printf("Numero:%2d Saldo:%.f situacao: ", cheque.num, cheque.valor);
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
/*
obtemSituacao
Entrada: um cheque
Retorno: O código da situação	do cheque
*/
int obtemSituacao(Cheque cheque)
{
    return cheque.situacao;
}
/*
obtemValor
Entrada: um cheque
Retorno: O valor do cheque
*/
float obtemValor(Cheque cheque)
{
    return cheque.valor;
}
/*
obtemNumero
Entrada: um cheque
Retorno: O número do cheque
*/
int obtemNumero(Cheque cheque)
{
    return cheque.num;
}
/*
compensaCheque
Entrada/Saı́da: um cheque
Retorno: Código 0(sucesso),1(erro)
Descrição: Altera a situação do cheque para 2 (compensado)
O cheque só pode ser compensado se	a situação for igual a 1(emitido)*/
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
/*emiteCheque
Entrada/Saı́da:	um cheque
Entrada:	Valor do cheque
Retorno:	Código 0(sucesso),	1(erro)
Descrição:	Atribui um valor ao cheque e altera a situação para o código1(Emitido).O cheque só 	pode ser emitido se a situação for igual a 0 (em branco)*/
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
