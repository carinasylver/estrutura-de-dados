#ifndef ALUNO_H_INCLUDED
#define ALUNO_H_INCLUDED

typedef struct data
{
  int dia,
      mes,
      ano;

} Data;

typedef struct aluno
{
  int num_matricula;
  Data data_nasc;

} Aluno;

int calcula_idade(Data *data_hj, Data *data_nasc);

#endif // ALUNO_H_INCLUDED
