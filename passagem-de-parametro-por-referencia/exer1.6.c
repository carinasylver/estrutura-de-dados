#include <stdio.h>

int duplaClassificada(int *a, int *b);

int main(void)
{
    int a, b;

    while (a != b)
    {
        printf("\ninforme dois numeros:\n");
        scanf("%d %d", &a, &b);

        if (a != b)
        {
            duplaClassificada(&a, &b);

            printf("ordem dos valores: %d %d", a, b);
        }
    }

    return 0;
}

int duplaClassificada(int *a, int *b)
{
    int aux;

    if ((*a + *b) % 2 == 0)
    {
        if (*a > *b)
        {
            aux = *a;
            *a = *b;
            *b = aux;
        }
    }

    else
    {
        if (*b > *a)
        {
            aux = *b;
            *b = *a;
            *a = aux;
        }
    }
}