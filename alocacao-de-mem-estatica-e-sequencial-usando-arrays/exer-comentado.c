#include <stdio.h>
#include <stdlib.h>

#define MAX_NODOS 5 // TAMANHO DO ARRAY

#define SUCESSO 0
#define LISTA_VAZIA 1
#define LISTA_CHEIA 2
#define CODIGO_INEXISTENTE 3

/*DEFINICAO DE TIPOS DE DADOS*/

typedef struct _listaCF ListaCF;

typedef struct _dados
{
    int cod;
    float peso;
} Dados;

typedef struct _listaCF
{
    int n;              // qdt de posicoes ocupadas na lista
    Dados v[MAX_NODOS]; // tamanho do array ate 5
} ListaCF;

/*--------------------------------
 *  PROTOTIPOS DAS FUNCOES
 */
void criaLista(ListaCF *lista);
int incluiNoFim(ListaCF *lista, Dados dado);
void exibe(ListaCF *lista);
int quantidadeDeNodos(ListaCF *lista);
int estaCheia(ListaCF *lista);
int estaVazia(ListaCF *lista);
int excluiDoFim(ListaCF *lista, Dados *dado);
int incluiNoInicio(ListaCF *lista, Dados dado);
int excluiDoInicio(ListaCF *lista, Dados *dado);
int consultaPorCodigo(ListaCF *lista, Dados *dado, int consultaCod);
int incluiAntes(ListaCF *lista, Dados dado, int cod);
int excluiNodo(ListaCF *lista, int consultaCod);

// FUNCAO PRINCIPAL
int main(void)
{
    ListaCF lista;
    Dados dado;
    int opcao, cod, consultaCod, pesqCod;

    criaLista(&lista);

    opcao = 1;
    while (opcao != 0)
    {
        puts("\n========= MENU =========");
        puts("1-inclui no fim");
        puts("2-exibe lista");
        puts("3-quantidade de nodos");
        puts("4-exibe situacao da lista");
        puts("5-exclui do fim");
        puts("6-inclui no inicio");
        puts("7-exclui do inicio");
        puts("8-consulta por codigo");
        puts("9-inclui antes");
        puts("10-exclui nodo");
        puts("0-fim");

        printf("\ninforme a operacao: ");
        scanf("%d", &opcao);
        system("clear");

        switch (opcao)
        {
        case 1:
            printf("informe o codigo(decimal): ");
            scanf("%d", &dado.cod);

            printf("informe o peso: ");
            scanf("%f", &dado.peso);
            system("clear");

            if (incluiNoFim(&lista, dado) == LISTA_CHEIA)
            {
                printf("\nERRO: a lista esta cheia!\n"); // quando lista->n == 5
            }
            else
            {
                printf("\ncod: %d | peso: %.2f\nincluidos com SUCESSO na ultima posicao da lista!\n", dado.cod, dado.peso);
            }
            break;
        case 2:
            exibe(&lista);
            break;
        case 3:
            printf("\nquantidade de nodos na lista: %d\n\n", quantidadeDeNodos(&lista));
            break;
        case 4:
            if (estaCheia(&lista) == 1)
            {
                puts("\nERRO: lista CHEIA!\n");
            }
            else if (estaVazia(&lista) == 1)
            {
                puts("\na lista esta VAZIA\n");
            }
            else
            {
                puts("\nainda ha espaco na lista\n");
            }
            break;
        case 5:
            if (excluiDoFim(&lista, &dado) == LISTA_VAZIA)
            {
                puts("\nERRO: a lista esta VAZIA\n");
            }
            else
            {
                printf("\ncod: %d | peso: %.2f\nexcluidos com SUCESSO!\n", dado.cod, dado.peso);
            }
            break;
        case 6:
            printf("\ninforme o codigo: ");
            scanf("%d", &dado.cod);

            printf("informe o peso: ");
            scanf("%f", &dado.peso);

            if (incluiNoInicio(&lista, dado) == LISTA_CHEIA)
            {
                printf("\nERRO: a lista esta cheia\n");
            }
            else
            {
                printf("\ncod: %d | peso: %.2f\nincluidos com SUCESSO na 1a posicao da lista!\n", dado.cod, dado.peso);
            }
            break;
        case 7:
            if (excluiDoInicio(&lista, &dado) == LISTA_VAZIA)
            {
                printf("ERRO: A lista esta vazia\n");
            }
            else
            {
                printf("\ncod: %d | peso: %.2f\nexcluidos com SUCESSO!\n", dado.cod, dado.peso);
            }
            break;
        case 8:
            printf("informe o codigo: ");
            scanf("%d", &consultaCod);

            if (consultaPorCodigo(&lista, &dado, consultaCod) == CODIGO_INEXISTENTE)
            {
                puts("\nERRO: Codigo inexistente\n");
            }
            else
            {
                puts("----------------------------");
                printf("\ncodigo: %d peso: %.2f\n", dado.cod, dado.peso);
            }
            break;
        case 9:
            printf("informe o codigo: ");
            scanf("%d", &dado.cod);
            printf("informe o peso: ");
            scanf("%f", &dado.peso);
            printf("informe o codigo para consulta: ");
            scanf("%d", &cod);

            pesqCod = incluiAntes(&lista, dado, cod);
            if (pesqCod == LISTA_CHEIA)
            {
                puts("\nERRO: a lista esta cheia");
            }
            else if (pesqCod == CODIGO_INEXISTENTE)
            {
                puts("\nERRO: codigo inexistente\n");
            }
            else
            {
                puts("\ndados incluidos com SUCESSO!");
            }
            break;

        case 10:
            printf("informe o codigo dos dados para exclusao: ");
            scanf("%d", &consultaCod);

            pesqCod = excluiNodo(&lista, consultaCod);
            if (pesqCod == LISTA_VAZIA)
            {
                puts("\nERRO: a lista esta VAZIA");
            }
            else if (pesqCod == CODIGO_INEXISTENTE)
            {
                puts("\nERRO: codigo inexistente\n");
            }
            else
            {
                printf("\ncod: %d | peso: %.2f\nexcluidos com SUCESSO!\n", dado.cod, dado.peso);
            }
            break;                  
        }
        if(opcao != 2)
        {
            exibe(&lista);
        } 
    } // fim do while

    return 0;
}
/*-----------------
criaLista
Saída: uma lista vazia
Retorno: nenhum
Descrição: Cria uma lista vazia
*/
void criaLista(ListaCF *lista)
{
    lista->n = 0;
}

/*-----------------
incluiNoFim
E/S: Uma lista
Entrada: um dado do tipo Dado
Retorno: Código de erro: SUCESSO ou LISTA_CHEIA
Descrição: Inclui o dado na última posição da lista
*/
int incluiNoFim(ListaCF *lista, Dados dado)
{
    if (estaCheia(lista)) // lista->n == MAX_NODOS
        return LISTA_CHEIA;
    else
    {
        lista->v[lista->n] = dado; // insercao no fim nao ha deslocamento dos dados
        lista->n++;
        return SUCESSO;
    }
}
/*-----------------
exibe
Entrada: Uma lista
Retorno: Nenhum.
Descrição: Exibe todos os nodos da lista
*/
void exibe(ListaCF *lista)
{
    puts("---------------------------");
    puts("Lista:");
    for (int i = 0; i < lista->n; i++)
    {

        printf("\ncodigo: %d | peso: %.2f\n", lista->v[i].cod, lista->v[i].peso);
        puts("---------------------------");
    }
}
/*
quantidadeDeNodos
Entrada: Uma lista.
Retorno: A quantidade de nodos existente na lista.
*/
int quantidadeDeNodos(ListaCF *lista)
{
    return lista->n;
}
/*
estaCheia
Entrada: Uma lista.
Retorno: 1 se a lista está cheia e 0 caso contrário.
*/
int estaCheia(ListaCF *lista)
{
    if (lista->n == MAX_NODOS)
    {
        return 1; // lista cheia
    }
    else
    {
        return 0;
    }
}
/*
estaVazia
Entrada: Uma lista.
Retorno: 1 se a lista está vazia e 0 caso contrário.
*/
int estaVazia(ListaCF *lista)
{
    if (lista->n == 0)
    {
        return 1; // lista vazia
    }
    else
    {
        return 0;
    }
}
/*
excluiDoFim
E/S: Uma lista.
Saída: O dado armazenado na última posição da lista.
Retorno: Código de erro: SUCESSO ou LISTA_VAZIA.
Descrição: Exclui o nodo armazenado na última posição da
lista.
*/
int excluiDoFim(ListaCF *lista, Dados *dado)
{
    if (estaVazia(lista)) // lista->n == 0
    {
        return LISTA_VAZIA;
    }
    else
    {
        *dado = lista->v[lista->n - 1]; // exclusao do fim nao há deslocamento dos dados
        lista->n--;
        return SUCESSO;
    }
}
/*
incluiNoInicio
E/S: Uma lista
Entrada: um dado do tipo Dado
Retorno: Código de erro: SUCESSO ou LISTA_CHEIA
Descrição: Inclui o dado na primeira posição da lista.
*/
int incluiNoInicio(ListaCF *lista, Dados dado)
{
    if (estaCheia(lista)) // lista->n == MAX_NODOS
    {
        return LISTA_CHEIA;
    }
    else
    {
        // deslocamento de todos os elem para poder inserir no inicio da lista
        for (int i = lista->n - 1; i >= 0; i--) // lista->n - 1 me diz o ultimo elem q inseri no final da lista
        {
            lista->v[i + 1] = lista->v[i]; // posicao da frente recebe os dados na posicao i anterior a ela
        }
        lista->v[0] = dado; // apos o for deslocando um posicao para frente todos os elem, abro espaco na 1 posicao e insiro o dado no inicio da lista
        lista->n++;

        return SUCESSO;
    }
}
/*
excluiDoInicio
E/S: Uma lista.
Saída: O dado armazenado na primeira posição da lista.
Retorno: Código de erro: SUCESSO ou LISTA_VAZIA
Descrição: Exclui o nodo armazenado na primeira posição da
lista.
*/
int excluiDoInicio(ListaCF *lista, Dados *dado)
{
    if (estaVazia(lista))
    {
        return LISTA_VAZIA;
    }
    else
    {
        *dado = lista->v[0];
        for (int i = 0; i < lista->n - 1; i++) // n eh a ultima posicao valida e n-1 eh a ultima pos preenchida
        {
            lista->v[i] = lista->v[i + 1];
            // posicao i q esta atras recebe os dados da posicao i+1 q esta na frente
        }
        lista->n--;
        return SUCESSO;
    }
}
/*consultaPorCodigo
Entrada: Uma lista
Entrada: Um código.
Saída: O dado que possui o código informado.
Retorno: SUCESSO ou CODIGO_INEXISTENTE
*/
int consultaPorCodigo(ListaCF *lista, Dados *dado, int consultaCod)
{
    int k, i = 0;

    // enquanto i for menor q a qtd de elem na lista e cod q tiver na posicao i for != do cod q eu passar eu vou andando na lista a procura ate achar o cod
    while (i < lista->n && lista->v[i].cod != consultaCod)
        i++;
    if (i == lista->n) // cheguei no final da lista e nao achei
        return CODIGO_INEXISTENTE;

    *dado = lista->v[i]; // achei o cod pego os dados da pos i  e guardo dentro do conteudo da struct dados q passei por referencia
    return SUCESSO;
}
/*
incluiAntes
E/S: Uma lista
Entrada: Um código
Entrada: O dado que será incluído na lista ANTES daquele
que possui o código passado como argumento.
Retorno: SUCESSO, CODIGO_INEXISTENTE ou LISTA_CHEIA.
Descrição: Inclui o dado antes do nodo que possui o código
passado como argumento.
*/
int incluiAntes(ListaCF *lista, Dados dado, int cod)
{
    int i = 0;
    if (estaCheia(lista)) // lista->n == MAX_NODOS
    {
        return LISTA_CHEIA;
    }
    else
    {
        while (i < lista->n && lista->v[i].cod != cod)
            i++;
        if (i == lista->n) // cheguei no final da lista e nao achei
        {
            return CODIGO_INEXISTENTE;
        } 
        else
        {
            // deslocamento de todos os elem para poder inserir no inicio da lista
            for (int i = lista->n - 1; i >= 0; i--) // lista->n - 1 me diz o ultimo elem q inseri no final da lista
            {
                lista->v[i + 1] = lista->v[i]; // posicao da frente v[i + 1] recebe os dados na posicao v[i] anterior a ela
            }
            lista->v[i] = dado; // apos o for deslocando um posicao para frente todos os elem, abro espaco na 1 posicao e insiro o dado no inicio da lista
            lista->n++;
            return SUCESSO;
        }
    }
}
/*excluiNodo
E/S: Uma lista
Entrada: Um código
Saída: O nodo que contém o código passado como
argumento.
Retorno: SUCESSO, CODIGO_INEXISTENTE
Descrição: Exclui o nodo que possui o código passado
como argumento
*/
int excluiNodo(ListaCF *lista, int consultaCod) // revisado
{
    int k, i = 0;

    if (estaVazia(lista))
    {
        return LISTA_VAZIA;
    }
    // enquanto i for menor q a qtd de elem na lista e cod q tiver na posicao i for != do cod q eu passar eu vou andando na lista a procura ate achar o cod
    while (i < lista->n && lista->v[i].cod != consultaCod)
        i++;
    if (i == lista->n) // cheguei no final da lista e nao achei
        return CODIGO_INEXISTENTE;

    for (k = i; k < lista->n; k++) // apos achar o cod eh feito o deslocamento de todos os elem q estao um posicao a frente dele v(k+1) p atras v[k]
    {                              // k=i  i eh a posicao q achei o cod
        lista->v[k] = lista->v[k + 1];
    }
    lista->n--; // diminuo a qtd de elem da lista
    return SUCESSO;
}