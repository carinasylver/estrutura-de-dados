#include <stdio.h>
#include <stdlib.h>

#define SUCESSO 0
#define FILA_VAZIA 1
#define FALTOU_MEMORIA 2

typedef struct nodo Nodo;

typedef struct _dados
{
    int cod;
    float peso;
} Dados;

typedef struct nodo
{
    Dados info; /*informacao armazenada*/
    Nodo *prox; /*endereco para o proximo no*/
} Nodo;

typedef struct _filaSE
{
    Nodo *inicio;
    Nodo *fim;
} FilaSE;

void criaFila(FilaSE *fila);
int insere(FilaSE *fila, Dados dados);
int retira(FilaSE *fila, Dados *dados);
int estaVazia(FilaSE *fila);
int quantidadeDeNodos(FilaSE fila);
int consultaInicio(FilaSE *fila, Dados *dados);
void exibe(FilaSE fila);


int main(void)
{
    FilaSE fila;
    Dados dados;
    int opcao;

    criaFila(&fila);
    do
    {
        puts("\n========= MENU =========");
        puts("1.insere na fila");
        puts("2.retira da fila");
        puts("3.quantidade de nodos");
        puts("4.exibe situacao da fila");
        puts("5.consulta inicio da fila");
        puts("0.fim");

        printf("\ninforme a operacao: ");
        scanf("%d", &opcao);
        system("clear");

        switch (opcao)
        {
        case 1:
            printf("\ninforme o codigo(decimal): ");
            scanf("%d", &dados.cod);

            printf("informe o peso: ");
            scanf("%f", &dados.peso);

            if (insere(&fila, dados) == FALTOU_MEMORIA)
            {
                puts("\nERRO: FALTOU MEMORIA!\n");
            }
            else
            {
                puts("----------------------------------");
                puts("\ndados incluidos com SUCESSO!\n");
            }
            break;
        case 2:

            if (retira(&fila, &dados) == FILA_VAZIA)
            {
                puts("----------------------------");
                printf("\nERRO: a Fila esta VAZIA!\n\n");
            }
            else
            {
                puts("--------------------------------");
                printf("\ncodigo: %d | peso %.2f\n\nremovidos da fila com SUCESSO!\n\n", dados.cod, dados.peso);
            }
            break;
        case 3:
         puts("-------------------------------");
            printf("\nquantidade de nodos na Fila: %d\n\n", quantidadeDeNodos(fila));
            break;
        case 4:
            if (estaVazia(&fila) == 1)
            {
                puts("------------------------");
                puts("\na fila esta VAZIA\n");
            }
            else
            {
                puts("-----------------------------------");
                puts("\na fila possui 1 ou mais nodos\n");
            }
            break;
        case 5:
            if (consultaInicio(&fila, &dados) == FILA_VAZIA)
            {
                puts("------------------------------");
                puts("\nERRO: a fila esta VAZIA\n");
            }
            else
            {
                puts("--------------------------------------------------");
                printf("\ndados do inicio da fila: cod: %d  peso: %.2f\n\n", dados.cod, dados.peso);
            }
            break;
        } // fim do switch case
        // Ap??s a execu????o de cada opera????o deve ser exibida a pilha atrav??s da opera????o exibe.
        exibe(fila);

    } while (opcao != 0);
    // enquanto for diferente da opcao 0 execute

    return 0;
}
/*
criaFila
Sa??da: uma fila vazia
Retorno: nenhum
Descri????o: Cria uma fila vazia
*/
void criaFila(FilaSE *fila)
{
    fila->inicio = NULL;
    fila->fim = NULL;
}
/*
insere
E/S: Uma fila
Entrada: um dado do tipo Dado
Retorno: C??digo de erro: SUCESSO ou FALTOU_MEMORIA
Descri????o: insere o dado na fila
*/
int insere(FilaSE *fila, Dados dados)
{
    Nodo *nNodo;
    nNodo = (Nodo *)malloc(sizeof(Nodo));
    if (nNodo == NULL) //nNodo n??o alocado na memoria
    {
        return FALTOU_MEMORIA;
    }
    nNodo->info = dados;
    nNodo->prox = NULL;
    if (fila->inicio == NULL) // caso a fila vazia inserir elemento
    {
        fila->inicio = nNodo;
        // fila->fim = nNodo;
        // return SUCESSO;
        // movidos p o fim da condicional
    }
    else //caso a fila ja possuir elemento ser?? sempre inserido outro elem no fim
    {
        fila->fim->prox = nNodo; // encadeamento da lista
        // fila->fim = novo;
        // return SUCESSO;
        // movidos p o fim da condicional
    }
    fila->fim = nNodo; // variavel fim tem q ser sempre atualizada.
    return SUCESSO;
}

void exibe(FilaSE fila)
{
    Nodo *pAux;
    pAux = fila.inicio;
    puts("---------------------------------------------------");
    printf("[EnderecoInicio]\n %p \n", fila.inicio);
    printf("Exibindo a FILA ENCADEADA:\n");
    printf("[EnderecoNodo]       [cod] [peso] [EnderecoProxNodo]\n");
    while (pAux != NULL)
    {
        printf("  %p -   %3d  %.2f - %p\n", pAux, pAux->info.cod, pAux->info.peso, pAux->prox);       
        pAux = pAux->prox;
    }
}
/*
estaVazia
Entrada: Uma fila.
Retorno: 1 se a fila est?? vazia e 0 caso contr??rio.
*/
int estaVazia(FilaSE *fila)
{
    if (fila->inicio == NULL)
    {
        return FILA_VAZIA;
    }
    else
    {
        return SUCESSO;
    }
}
/*
retira
E/S: Uma fila
Sa??da: um dado
Retorno: C??digo de erro: SUCESSO ou FILA_VAZIA.
Descri????o: retira um dado da fila
*/
int retira(FilaSE *fila, Dados *dados)
{
    Nodo *nNodo;
    if (estaVazia(fila))//fila->inicio == NULL
    {
        return FILA_VAZIA;
    }
    else
    {
        *dados = fila->inicio->info;
        nNodo = fila->inicio;
        fila->inicio = fila->inicio->prox;
        free(nNodo);
        return SUCESSO;
    }
}
int quantidadeDeNodos(FilaSE fila)
{
    Nodo *pAux;
    int cont = 0;

    pAux = fila.inicio;
    while (pAux != NULL)
    {
        cont++;
        pAux = pAux->prox;
    }
    return (cont);
}
/*
consulta
Entrada: Uma fila.
Sa??da: O dado que est?? na frente da fila
Retorno: SUCESSO ou FILA_VAZIA
*/
int consultaInicio(FilaSE *fila, Dados *dados)
{
    Nodo *nNodo;
    if (estaVazia(fila))
    {
        return FILA_VAZIA;
    }
    else
    {
        nNodo = fila->inicio;
        *dados = nNodo->info;
        return SUCESSO;
    }
}