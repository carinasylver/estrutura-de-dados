#include <stdio.h>
/*
1.3 Escreva	uma	função	chamada	maiorNumero que	receba	como entrada dois inteiros positivos e RETORNE o maior deles
ou o valor -1 se eles forem iguais. Considere que os valores de entrada são sempre positivos(não
é	necessário validar).
Escreva	 um	 programa em C para ler um valor N. A seguir ler N duplas de inteiros(considere que serão	informado apenas valores	positivos).	Para cada dupla	informada exibir o maior elemento ou a frase “Eles são	iguais”.Para obter o maior elemento	deve ser	utilizada a função	maior Numero.
exemplo:
[Entrada] [Saída]
3
20 15       20
7  12       12
5  5        Eles são iguais
*/

int maiorNumero(int a, int b);

int main(void)
{
    int N, a, b, maior;

    /*Escreva	 um	 programa em C para ler um valor N. A seguir ler N duplas de inteiros(considere que serão	informado apenas valores	positivos)*/

    printf("informe um valor inteiro para N:");
    scanf("%d", &N);

    for (int i = 0; i < N; i++)
    {
        printf("\ninforme o valor de a:");
        scanf("%d", &a);
        printf("informe o valor de b:");
        scanf("%d", &b);

        maior = maiorNumero(a, b);// chama a funcao
        //retorno da funcao
        if (maior>=0)
        {
            printf("\nmaior: %d\n", maior);
        }
        else
        {
            printf("\neles sao iguais\n");
        }
    }

    return 0;
}
int maiorNumero(int a, int b)
{
    if (a > b)
    {   //retorna o maior para  maior = maiorNumero(a, b);
        return a;
    }
    else if (a < b)
    {
        return b;
    }
    else
    {  //valor -1 se eles forem iguais.
        return -1;
    }
}