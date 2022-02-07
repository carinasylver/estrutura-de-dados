#include <stdio.h>

int duplaCrescente(int *a, int *b);

int main(void)
{

    int a, b;

    while (a != b)
    {
        printf("\ninforme dois numeros:\n");
        scanf("%d %d", &a, &b);

        if (a != b)
        {
            duplaCrescente(&a, &b);
            printf("ordem crescente: %d %d", a, b);
        }
    }

    return 0;
}

int duplaCrescente(int *a, int *b)
{
    int aux;

    if (*a > *b)
    {
        aux = *a;
        *a = *b;
        *b = aux;
    }
}
