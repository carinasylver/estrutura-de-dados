#include <stdio.h>
#define TAM 20
/*1.2 Escreva uma função chamada exibeDivisores que exiba na tela os divisores do inteiro passado com argumento
Escreva	um programa em C para imprimir os números de 1a20 com seus respectivos	divisores.Cada conjunto de divisores deve ser	impresso com afunção exibeDivisores. A saı́da deve ser impressa conformeo formato abaixo.
*/

void exibeDivisores(int n);//prototipo da funcao

int main(void)
{

    //loop de 20 numeros
   for (int i = 1; i <= TAM; i++)
    {
        //exibe os numeros de 1-20
        printf("\n%d:", i);

        //chama a funcao. envia uma copia i de 1-20 como parametro e enviada p funcao
        exibeDivisores(i);
    }  

    return 0;
}

//int n recebe i e faz o calculo dos seus divisores
void exibeDivisores(int n)
{
    //int divisor;

    for ( int i = 1; i <= n; i++)
    {
        //divisor = n % i;
        //if (divisor == 0)  

        if ((n % i)==0)
        {
            printf(" %d",i);
        }
    }
    printf("\n");
}