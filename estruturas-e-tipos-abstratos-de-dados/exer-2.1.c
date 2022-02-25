#include <stdio.h>
#define TAM 2
/*2.1 Definir um tipo de dado chamado Horario para armazenar um horário composto de: hora,minuto,segundo.
Escreva um programa em C para ler dois horários.Escreva o menor horário no formato HH:MM:SS.No caso de igualdade escrever a mensagem "Horários iguais".*/

/*Definir um tipo de dado chamado Horario para armazenar um	horário composto de: hora,minuto,segundo.*/
typedef struct horario
{
    int hora, minuto, segundo;

} Horario;

void lehorario(Horario *phr);
int relogio(Horario *phms);

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
    // No caso de igualdade escrever a mensagem "Horários iguais".*/
    if (hr1 == hr2)
    {
        printf("Horarios iguais");
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
    // Escreva o menor horário no formato HH:MM:SS
    printf("menor horario %02d:%02d:%02d\n", resultado->hora, resultado->minuto, resultado->segundo);

    return 0;
}
int relogio(Horario *phms)
{
    int hms = 0;

    hms = phms->hora * 3600 + phms->minuto * 60 + phms->segundo;

    return hms;
}
