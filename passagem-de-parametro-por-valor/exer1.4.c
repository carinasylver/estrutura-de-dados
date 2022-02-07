#include <stdio.h>

int main(void)
{

    int Q;

    printf("informe um valor para Q: ");
    scanf("%d", &Q);
    while (Q > 10 || Q < 0)
    {
        printf("\nNAO EH PERMITIDO VALOR MAIOR QUE 10\n");
        printf("\ninforme Q: ");
        scanf("%d", &Q);
    }

    int vetZ[Q], vetW[Q], Y, cont = 0;

    printf("Digite um valor para cada vetor\n");
    for (int i = 0; i < Q; i++)
    {
        printf("vetorZ[%d]: ", i);
        scanf("%d", &vetZ[i]);
    }
     printf("informe um valor para Y:");
    scanf("%d", &Y);

    for (int i = 0; i < Q; i++)
    {
        if (vetZ[i] > Y)
        {
            vetW[cont] = vetZ[i];
            cont++;
        }
    }
    for (int i = 0; i < cont; i++)
    {
        {
            printf("%d ", vetW[i]);
        }
    }
    printf("\n");

    return 0;
}
