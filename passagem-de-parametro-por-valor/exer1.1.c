#include <stdio.h>

int main(void)
{
    int Q, sexo;
    float alturaM, alturaF, media;
     

    printf("informe a qtd de alunos da turma: ");
    scanf("%d", &Q);

    float altura[Q];
    alturaM = altura[0];
    alturaF = altura[0];
    int cont = 0;

    for (int i = 0; i < Q; i++)
    {
        printf("informe o sexo ( 1 - masculino  2 - feminino) : ");
        scanf("%d", &sexo);

        if (sexo == 1)
        {
            printf("informe a altura : ");
            scanf("%f", &altura[i]);

            if (altura[i] > alturaM)
            {
                alturaM = altura[i];
            }
        }

        else
        {
            printf("informe a altura : ");
            scanf("%f", &altura[i]);

            alturaF += altura[i];
            cont++;
        }
    }
    printf("\naltura aluno mais alto: %.2fcm", alturaM);
    media = alturaF / cont;
    printf("\na media de altura das alunas: %.2fcm", media);

    return 0;
}