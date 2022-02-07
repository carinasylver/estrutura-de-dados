#include <stdio.h>
#define TAM 20

void exibeDivisores(int n);

int main(void)
{

    for (int i = 1; i <= TAM; i++)
    {
        printf("\n%d:", i);
        exibeDivisores(i);
    }

    return 0;
}

void exibeDivisores(int n)
{
    for (int i = 1; i <= n; i++)
    {
        if ((n % i)==0)
        {
            printf(" %d",i);
        }
    }
    printf("\n");
}