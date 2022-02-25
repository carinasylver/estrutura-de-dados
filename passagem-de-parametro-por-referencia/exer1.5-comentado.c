#include <stdio.h>
/*1.5 Escreva uma função em C chamada duplaCrescente que classifique 2 valores	inteiros passados como argumento em ordem crescente.
Entrada: dois números inteiros
Saída:	Os dois inteiros em ordem crescente.
Retorno: Nenhum
Escreva	um programa em C para ler uma quantidade indeterminada de duplas de inteiros. 
Escrever cada dupla em ordem crescente. Os valores em ordem crescente devem ser obtidos	através da chamada à função duplaCrescente. 
O programa termina quando os dois valores informados forem iguais (nesta situação os valores não devem ser impressos).
[Entrada] [Saída]
1 2         1 2
4 3         3 4
2 2
*/

/*Escreva uma função em C chamada duplaCrescente que classifique 2 valores inteiros passados como argumento em ordem crescente.*/
int duplaCrescente(int *a, int *b);

int main(void)
{

    int a, b;
/*Escreva um programa em C para ler uma quantidade indeterminada de duplas de inteiros.
Escrever cada dupla em  ordem crescente.*/
    while (a != b)
    {
        printf("\ninforme dois numeros:\n");
        scanf("%d %d", &a, &b);
        // O programa termina quando os dois valores informados forem iguais (nesta situação os valores não devem ser impressos).
        //se for diferentes a e b entra no if, do contrario encerra o programa
        if (a != b)
        {
            //Os valores em	ordem crescente devem ser obtidos através da chamada a função duplaCrescente.
            duplaCrescente(&a, &b);
            printf("ordem crescente: %d %d", a, b);
        }
       
    }

    return 0;
}

//Entrada:	Dois números inteiros
int duplaCrescente(int *a, int *b)
{
    int aux;

    if (*a > *b)
    {
        aux = *a;    
        *a = *b;
        *b = aux;
        //Saída:Os dois inteiros em ordem crescente.
        //Retorno:	Nenhum
    }
}
