#include "aluno.h"

int calcula_idade(Data *data_hj, Data *data_nasc)
{
    int aluno_idade = 0;

    aluno_idade = ((data_hj->dia + data_hj->mes + data_hj->ano) - (data_nasc->dia + data_nasc->mes + data_nasc->ano));

    return aluno_idade;
}
