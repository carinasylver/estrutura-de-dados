#include <stdio.h>
#include "horario.h"

/*Escreva	o menor	horário no formato	HH:MM:SS.No	caso de igualdade escrever a mensagem "Horários iguais".*/

int relogio(Horario *phms)
{
    int hms = 0;

    hms = phms->hora * 3600 + phms->minuto * 60 + phms->segundo;

    return hms;
}
