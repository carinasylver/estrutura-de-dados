#include <stdio.h>
#define TAM 2
#include "horario.h"

int main(void)
{

    Horario hr[TAM], *phms, *resultado;
    int hr1, hr2;

    for (int i = 0; i < TAM; i++)
    {
        printf("informe o %do horario (HH:MM:SS):\n", i + 1);
        scanf("%d %d %d", &hr[i].hora, &hr[i].minuto, &hr[i].segundo);
    }

    hr1 = relogio(&hr[0]);
    hr2 = relogio(&hr[1]);

    if (hr1 == hr2)
    {
        printf("horarios iguais\n");
        return 0;
    }
    else if (hr1 > hr2)
    {
        resultado = &hr[1];
    }
    else
    {
        resultado = &hr[0];
    }
    printf("menor horario %02d:%02d:%02d\n", resultado->hora, resultado->minuto, resultado->segundo);

    return 0;
}
