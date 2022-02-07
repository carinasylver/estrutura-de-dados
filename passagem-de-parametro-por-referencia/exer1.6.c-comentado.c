#include <stdio.h>
/*
1.6 Escreva	uma função chamada duplaClassificada que classifique 2 valores inteiros conforme o código
passado	como argumento	(0-ordem crescente	1-ordem	decrescente).
Entrada:	Um	código	que	identifica a ordem	de classificação(0-ordem crescente	1-ordem	decrescente).
Entrada:	Dois valores inteiros.
Saída:	Os	2 valores de entrada na	ordem desejada
Retorno:	Nenhum
Escreva	um programa para ler uma quantidade indeterminada de duplas	de	valores. Escrever cada	dupla em
ordem crescente se a soma dos elementos da dupla for par e em ordem decrescente se a soma for ı́mpar. Os
valores	em ordem (conforme	o caso)	devem ser obtidos através da chamada à função duplaClassificada.	O
programa termina quando	os	dois valores informados	forem iguais (nesta	situação	os	valores	não devem	ser
impressos).
[Entrada] [Saída]
1 2        2 1
4 3        4 3
2 4        2 4
10 2       2 10
1 3        1 3
5 3        3 5
2 2
*/

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
            /*Escreva uma função chamada duplaClassificada que classifique 2 valores inteiros conforme o código
            passado	como argumento	(0-ordem crescente	1-ordem	decrescente).*/
            duplaClassificada(&a, &b); // chama a funcao
            // retorna da funcao
            printf("ordem dos valores: %d %d", a, b);
        }
        /*programa termina quando os dois valores informados forem iguais (nesta situação os valores não devem ser
        impressos).*/
    }

    return 0;
}
/*Escreva uma função chamada duplaClassificada que	classifique	 2	valores	inteiros conforme o	código
passado	como argumento	(0-ordem	crescente	1-ordem	decrescente).*/
int duplaClassificada(int *a, int *b)
{
    int aux;
    // ordem crescente se a soma dos elementos da dupla for	par
    if ((*a + *b) % 2 == 0)
    {
        if (*a > *b)
        {
            aux = *a;
            *a = *b;
            *b = aux;
        }
    }
    // ordem decrescente se a soma for ı́mpar.
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