#ifndef HORARIO_H_INCLUDED
#define HORARIO_H_INCLUDED
#define TAM 2

typedef struct horario
{
    int hora,
        minuto,
        segundo;
} Horario;

void lehorario(Horario *phr);
int relogio(Horario *phms);

#endif // HORARIO_H_INCLUDED
