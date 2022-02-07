#include <stdio.h>

int maiorNumero(int a, int b);

int main(void)
{
    int N, a, b, maior;

    printf("informe um valor inteiro para N:");
    scanf("%d", &N);

    for (int i = 0; i < N; i++)
    {
        printf("\ninforme o valor de a:");
        scanf("%d", &a);
        printf("informe o valor de b:");
        scanf("%d", &b);

        maior = maiorNumero(a, b);

        if (maior >= 0)
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
    {
        return a;
    }
    else if (a < b)
    {
        return b;
    }
    else
    {
        return -1;
    }
}