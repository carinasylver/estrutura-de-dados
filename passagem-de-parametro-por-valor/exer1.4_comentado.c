#include <stdio.h>
/*
1.4 Escreva	um programa em	C para ler um inteiro Q(máximo	10).A seguir ler um vetorZ de Q elementos e
um valor Y.	Copiar todos os	elementos maiores que Y	 que estão	no vetor Z para um vetorW (sem deixar
elementos vazios entre os valores copiados).Escrever o vetorW após o término cópia.
[Entrada] [Saída]
10
2 15 14 18 9 13 0 45 12 21
14
15 18 45 21
*/

int main(void)
{

    int Q;

    // escreva	um programa em	C para ler um inteiro Q(máximo	10).

    printf("informe um valor para Q: ");
    scanf("%d", &Q);
    while (Q > 10 || Q < 0)
    {
        printf("\nNAO EH PERMITIDO VALOR MAIOR QUE 10\n");
        printf("\ninforme Q: ");
        scanf("%d", &Q);
    }

    // A seguir ler um vetorZ de Q elementos

    int vetZ[Q], vetW[Q], Y, cont = 0;

    printf("Digite um valor para cada vetor\n");
    for (int i = 0; i < Q; i++)
    {
        printf("vetorZ[%d]: ", i);
        scanf("%d", &vetZ[i]);
    }
    // e um valor Y.
    printf("informe um valor para Y:");
    scanf("%d", &Y);

    // Copiar todos os elementos maiores que Y que estão no vetor Z para um vetorW	(sem deixar	elementos vazios entre os valores copiados).

    for (int i = 0; i < Q; i++)
    {
        if (vetZ[i] > Y)
        {
            vetW[cont] = vetZ[i];
            cont++;
        }
    }
    // Escrever o vetorW após o término cópia.
    for (int i = 0; i < cont; i++)
    {
        {
            printf("%d ", vetW[i]);
        }
    }
    printf("\n");

    return 0;
}
