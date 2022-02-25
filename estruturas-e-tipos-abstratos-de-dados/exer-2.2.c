#include <stdio.h>
/*
Definir um tipo chamado ALUNO para armazenar os seguintes dados de um aluno: número de matrı́cula e data de nascimento (tipo Data).
Escrever um programa em C para ler a data de hoje armazenando-a em uma variável do tipo Data.A seguir ler uma quantidade indeterminada de dados de alunos(Aluno). Para cada aluno lido escrever se ele já completou 18anos até a data informada. O programa termina ao ser informado um valor negativo para a matrı́cula.Nesta situação	a data de nascimento não deve ser lida
*/

// estruturas
typedef struct data
{
    int dia,
        mes,
        ano;

} Data;

// Definir um tipo chamado ALUNO para armazenar os seguintes dados de um aluno: número de matrı́cula e data de nascimento (tipo Data).
typedef struct aluno
{
    int num_matricula;
    Data data_nasc; // struct dentro de outra struct

} Aluno;

// protipo da funcao
int calcula_idade(Data *data_hj, Data *data_nasc);

int main(void)
{

    Data data_atual, /* variável do tipo Data*/ *data_hj, *data_nasc;
    Aluno aluno; // variável do tipo Data
    int aluno_idade;

    /*Escrever um programa em C para ler a data de hoje armazenando-a em uma variável do tipo Data.*/
    printf("\ninforme a data de hoje:(dia:mes:ano)\n");
    scanf("%d %d %d", &data_atual.dia, &data_atual.mes, &data_atual.ano);

    /*A seguir ler uma quantidade indeterminada de dados de alunos(Aluno).*/
    data_hj = &data_atual;
    do
    {
        // O programa termina ao ser informado um valor negativo para a matrı́cula. Nesta situação a data de nascimento não deve ser lida
        printf("\ninforme seus dados: matricula(11 caracteres):");
        scanf("%d", &aluno.num_matricula);
        if (aluno.num_matricula < 0)
        {
            return 0;
        }

        printf("\ninforme a data do seu aniversario:(dia:mes:ano)\n");
        scanf("%d %d %d", &aluno.data_nasc.dia, &aluno.data_nasc.mes, &aluno.data_nasc.ano);

        data_nasc = &aluno.data_nasc;

        aluno_idade = calcula_idade(data_hj, data_nasc);

        if (aluno_idade >= 18)
        {
            printf("voce EH maior de idade!\n");
        }
        else
        {
            printf("voce NAO eh maior de idade!\n");
        }

    } while (1);

    return 0;
}

int calcula_idade(Data *data_hj, Data *data_nasc)
{
    int aluno_idade = 0;

    aluno_idade = ((data_hj->dia + data_hj->mes + data_hj->ano) - (data_nasc->dia + data_nasc->mes + data_nasc->ano));

    return aluno_idade;
}
