#include <stdio.h>
/*1.1 Escreva um programaem	C para ler um valor Q que representa a quantidade de alunos de uma turma.
A seguir lerQ pares	de dados contendo, cada um, a altura e um codigo para masculino	(1)	e outro	para feminino
(2)	de cada	aluno.Calcular e escrever:
-A	altura do aluno mais alto da turma.
-A	média de altura das alunas.
*/
int main(void)
{
    int Q, sexo;
    float alturaM, alturaF, media;

    // Escreva um programa em C para ler um valor Q que representa a quantidade de alunos de uma turma.
    printf("informe a qtd de alunos da turma: ");
    scanf("%d", &Q);

    //qtd de alturas q receber em Q
    float altura[Q];
    ////nao sei qual é a altura maior. declaro inicialmente o 1 valor que colocar no indice 0 como maior
    alturaM = altura[0];
    alturaF = altura[0];
    ////////////////////////////////////////////////////////////
    // inicializo o contador das alturasF para calcular a media
    int cont = 0;

    // A seguir ler Q pares de dados contendo, cada um, a altura e um código para masculino	(1)	e outro	para feminino (2) de cada aluno.
    for (int i = 0; i < Q; i++)
    {
        printf("informe o sexo ( 1 - masculino  2 - feminino) : ");
        scanf("%d", &sexo);
        
       
        // se o o sexo informado for masculino entra no if
        if (sexo == 1)
        {
            printf("informe a altura : ");
            scanf("%f", &altura[i]);

            if (altura[i] > alturaM)
            {
                alturaM = altura[i];
            }
        }
        // do contrário entra no else
        else
        {
            printf("informe a altura : ");
            scanf("%f", &altura[i]);

            alturaF += altura[i]; // ou alturaF = alturaF + altura[i]
            cont++;//conta a qtd alturas
        }

    } // o loop acaba quando a qtd de alunos(Q) for finalizada

    // A altura	do	aluno mais	alto	da	turma.
    printf("\naltura aluno mais alto: %.2fcm", alturaM);
    // a media de altura das alunas
    media = alturaF / cont;
    printf("\na media de altura das alunas: %.2fcm", media);

    return 0;
}