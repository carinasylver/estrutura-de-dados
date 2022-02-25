#include <stdio.h>
#include "aluno.c"

int main(void)
{

    Data data_atual, *data_hj, *data_nasc;
    Aluno aluno;
    int aluno_idade;

    printf("\ninforme a data de hoje:(dia:mes:ano)\n");
    scanf("%d %d %d", &data_atual.dia, &data_atual.mes, &data_atual.ano);

    data_hj = &data_atual;
    do
    {
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
            printf("Voce EH maior de idade!\n");
        }
        else
        {
            printf("Voce NAO eh maior de idade!\n");
        }

    } while (1);

    return 0;
}