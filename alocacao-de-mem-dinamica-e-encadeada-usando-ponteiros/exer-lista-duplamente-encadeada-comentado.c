#include <stdio.h>
#include <stdlib.h>

#define SUCESSO 0
#define LISTA_VAZIA 1
#define FALTOU_MEMORIA 2
#define CODIGO_INEXISTENTE 3

typedef struct nodo Nodo; //utilizado p nao haver referencia circular dentro d estrutura

// DEFINE OS DADOS DA LISTA DUPLAMENTE ENCADEADA
typedef struct _dados
{
    int cod;
    float peso;
} Dados;
// DEFINE OS NODOS DA LISTA DUPLAMENTE ENCADEADA
typedef struct nodo
{
    Dados info; /*informacao armazenada*/
    Nodo *ant;  /*endereco para o nodo anterior*/
    Nodo *prox; /*endereco para o proximo nodo*/
} Nodo;

typedef struct _listaDE //estrutura de controle
{
    Nodo *inicio; /*ponteiro p/ o 1º nodo da lista*/
    Nodo *fim;    /* ponteiro p/ o ultimo nodo da lista*/
    int n;        /*contador de nodos*/
} ListaDE;

// DEFINE OS PROTOTIPOS DA FUNCOES
void criaLista(ListaDE *lista);
int incluiNoInicio(ListaDE *lista, Dados dado);
void exibe(ListaDE lista);
int quantidadeDeNodos(ListaDE lista);
int estaVazia(ListaDE *lista);
int excluiDoInicio(ListaDE *lista, Dados *dados);
int incluiNoFim(ListaDE *lista, Dados dados);
int excluiDoFim(ListaDE *lista, Dados *dados);
int incluiDepois(ListaDE *lista, Dados dados, int cod);
int excluiNodo(ListaDE *lista, Dados *dados, int cod);
int consultaPorCodigo(ListaDE *lista, Dados *dados, int consultaCod);

// FUNCAO PRINCIPAL
int main(void)
{
    ListaDE lista;
    Dados dados;
    int opcao, consultaCod, cod, op;

    criaLista(&lista);

    do
    {
        puts("\n========= MENU =========");
        puts("1-inclui no inicio");
        puts("2-exibe lista");
        puts("3-quantidade de nodos");
        puts("4-exibe situacao da lista");
        puts("5-exclui do inicio");
        puts("6-inclui no fim");
        puts("7-exclui do fim");
        puts("8-consulta por codigo");
        puts("9-inclui depois");
        puts("10-exclui nodo");
        puts("0-fim");

        printf("\ninforme a operacao: ");
        scanf("%d", &opcao);
        system("clear");

        switch (opcao)
        {
        case 1:
            printf("informe o codigo(decimal): ");
            scanf("%d", &dados.cod);

            printf("informe o peso: ");
            scanf("%f", &dados.peso);

            if (incluiNoInicio(&lista, dados) == FALTOU_MEMORIA)
            {
                puts("\nERRO: FALTOU MEMORIA!\n");
            }
            else
            {
                puts("-----------------------------");
                puts("\ndados incluidos com SUCESSO!\n");
            }
            break;
        case 2:
            exibe(lista);
            break;
        case 3:
            puts("----------------------------------");
            printf("\nquantidade de nodos na lista: %d\n\n", quantidadeDeNodos(lista));
            break;
        case 4:
            if (estaVazia(&lista) == 1)
            {
                puts("---------------------");
                puts("\na lista esta VAZIA!\n");
            }
            else
            {
                puts("--------------------------------");
                puts("\na lista possui 1 ou mais nodos\n");
            }
            break;
        case 5:
            if (excluiDoInicio(&lista, &dados) == LISTA_VAZIA)
            {
                puts("---------------------");
                puts("\nERRO: LISTA VAZIA!\n");
            }
            else
            {
                puts("--------------------------");
                printf("Lista:\ncodigo: %d | peso %.2f\n\nexcluidos com SUCESSO!!\n", dados.cod, dados.peso);
                puts("--------------------------");
            }
            break;
        case 6:
            printf("informe o codigo(decimal): ");
            scanf("%d", &dados.cod);

            printf("informe o peso: ");
            scanf("%f", &dados.peso);

            if (incluiNoFim(&lista, dados) == FALTOU_MEMORIA)
            {
                puts("\nERRO: FALTOU MEMORIA!\n");
            }
            else
            {
                puts("-----------------------------");
                puts("\ndados incluidos com SUCESSO!\n");
            }
            break;
        case 7:
            if (excluiDoFim(&lista, &dados) == LISTA_VAZIA)
            {
                puts("---------------------------");
                puts("\nERRO: a lista esta VAZIA!\n");
            }
            else
            {
                puts("--------------------------");
                printf("Lista:\ncodigo: %d | peso %.2f\n\nexcluidos com SUCESSO!!\n", dados.cod, dados.peso);
                puts("--------------------------");
            }
            break;
        case 8:
            printf("informe o codigo: ");
            scanf("%d", &consultaCod);

            if (consultaPorCodigo(&lista, &dados, consultaCod) == CODIGO_INEXISTENTE)
            {
                puts("--------------------------------------");
                puts("ERRO: Codigo informado eh inexistente!\n");
            }
            else
            {
                puts("---------------------------");
                puts("Codigo encontrado!");
                printf("codigo: %d | peso: %.2f\n", dados.cod, dados.peso);
            }
            break;
        case 9:
            printf("informe o codigo para consulta: ");
            scanf("%d", &cod);

            printf("informe o codigo que sera inserido: ");
            scanf("%d", &dados.cod);
            printf("informe o peso que sera inserido: ");
            scanf("%f", &dados.peso);

            op = incluiDepois(&lista, dados, cod);
            if (op == FALTOU_MEMORIA)
            {
                puts("\nERRO: faltou MEMORIA");
            }
            else if (op == LISTA_VAZIA)
            {
                puts("\nERRO: a lista esta VAZIA\n");
            }
            else if (op == CODIGO_INEXISTENTE)
            {
                puts("---------------------------");
                puts("\nERRO: codigo informado eh INEXISTENTE.\nnao foi possivel inserir os dados!!\n");
            }
            else
            {
                puts("\ndados incluidos com SUCESSO!");
                puts("---------------------------");
                printf("\ncodigo: %d | peso: %.2f\n", dados.cod, dados.peso);
            }
            break;
        case 10:
            printf("informe o codigo dos dados para exclusao: ");
            scanf("%d", &cod);

            op = excluiNodo(&lista, &dados, cod);
            if (op == LISTA_VAZIA)
            {
                puts("---------------------------");
                puts("ERRO: a lista esta VAZIA!\n");
            }
            else if (op == CODIGO_INEXISTENTE)
            {
                puts("---------------------------");
                puts("ERRO: codigo inexistente!\n");
            }
            else
            {
                puts("---------------------------");
                printf("codigo: %d| peso: %.2f\nexcluidos com SUCESSO!\n", dados.cod, dados.peso);
            }
            break;
        } // fim switch case
        if (opcao != 2)
        {
            exibe(lista);
        }
    } while (opcao != 0);
    return 0;
}
/*
criaLista
Saída: uma lista vazia
Retorno: nenhum
Descrição: Cria uma lista vazia
*/
// funcao q define a lista como vazia
void criaLista(ListaDE *lista)
{
    // a lista esta vazia quando o ponteiro para o inicio da lista ou fim aponta para null. ou seja nao aponta para nenhum nó.
    lista->inicio = NULL;
    lista->fim = NULL;
    lista->n = 0;
}
/*
incluiNoInicio
E/S: Uma lista
Entrada: um dado do tipo Dado
Retorno: Código de erro: SUCESSO ou FALTOU_MEMORIA
Descrição: Inclui o dado na primeira posição da lista
*/
int incluiNoInicio(ListaDE *lista, Dados dados)
{
    Nodo *pNodo;

    pNodo = (Nodo *)malloc(sizeof(Nodo));

    if (pNodo == NULL)
    {
        return FALTOU_MEMORIA; /*erro acontece quando nao tiver espaco na memoria suficiente para executar o prog.
        quando malloc nao encontra espaco na mem vai atribuir a nNodo o valor de null(nNodo==null). nesse caso eu nao vou ter nunca uma lista cheia pq nao eh vetor, nao tem tamanho pre-definido, sao espacos descontinuados na mem livres q eu vou ocupando, so vai ter erro caso a mem, nao tiver espaco disponivel, muito raro acontecer*/
    }
    else
    {
        pNodo->info = dados; // pNodo->info alimento o novo nodo com os dados que recebi por parametro. no endereco pNodo ache info e coloque nele o dado      
        pNodo->prox = lista->inicio; //vai executar em ambos os casos: lista vazia e ja com elem// o campo prox de pNodo aponta para onde lista->inicio esta apontando vazia. ou seja p null// se ja possuir elem pNodo prox aponta p o atual nodo q lista->inicio esta apontando
        if (estaVazia(lista))// lista->inicio == NULL
        {
            // lista->inicio=pNodo // removido p a final da condicional
            lista->fim = pNodo; // lista->fim aponta p o no inicial
        }
        else // lista ja existente
        {
            lista->inicio->ant = pNodo; //o campo ant do atual nodo inicial aponta p o novo pNodo q passa a ser o 1
        }
        lista->inicio = pNodo; // atualizamos o inicio// o campo inicio eh o mesmo para ambos os casos lista vazia sem nodo e ja existente com nodo.o campo inicio das 2 listas vai apontar p nNodo
        lista->n++;// incremento o n q eh a qtd de nodos da lista
        return SUCESSO;
    }
}
/*
exibe
Entrada: Uma lista
Retorno: Nenhum.
Descrição: Exibe todos os nodos da lista
*/
void exibe(ListaDE lista)
{
    Nodo *pAux;
    pAux = lista.inicio;
    puts("--------------------------------------------------------------------");
    printf("--------------Exibindo a LISTA DUPLAMENTE ENCADEADA-----------------\n");
    printf("enderecoInicio -> %p \n", lista.inicio);
    puts("--------------------------------------------------------------------");
    printf("[EnderecoAnterior][EnderecoNodoAtual] [cod] [peso] [EnderecoProx]\n");
    while (pAux != NULL)
    {
        printf(" %p  -  %p -  %5d   %.2f -  %p   \n", pAux->ant, pAux, pAux->info.cod, pAux->info.peso, pAux->prox);

        pAux = pAux->prox;
        puts("-------------------------------------------------------------------");
    }
    printf("EnderecoFim -> %p - N = %d\n", lista.fim, lista.n);
    puts("---------------------------------------------------------------------");
}
/*
quantidadeDeNodos
Entrada: Uma lista.
Retorno: A quantidade de nodos existente na lista.
*/
int quantidadeDeNodos(ListaDE lista)
{
    return lista.n; //n= qtd de nodos
}
/*
estaVazia
Entrada: Uma lista.
Retorno: 1 se a lista está vazia e 0 caso contrário.
*/
int estaVazia(ListaDE *lista)
{
    if (lista->inicio == NULL)
    {
        return 1; // lista vazia
    }
    else
    {
        return 0;
    }
}
/*
excluiDoInicio
E/S: Uma lista.
Saída: O dado armazenado na primeira posição da lista.
Retorno: Código de erro: SUCESSO ou LISTA_VAZIA Descrição:
Exclui o nodo armazenado na primeira posição da lista.
*/
int excluiDoInicio(ListaDE *lista, Dados *dados)
{
    Nodo *pNodo;

    if (estaVazia(lista)) // se a lista ta vazia aponta p null
    {
        return LISTA_VAZIA;
    }
    else // do contrario exclua o dado do inicio
    {
        *dados = lista->inicio->info;
        pNodo = lista->inicio; //lista->inicio aponta p o pNodo do inicio q sera excluido
        lista->inicio = pNodo->prox; //ou lista->inicio=lista->inicio->prox; l->inicio vai apontar p onde pNodo->prox aponta, se for unico nodo da lista p excluir; lista->inicio ira apontar para null, se ja possuir elem, lista->inicio irá apontar p/ onde pNodo->prox aponta, ou seja p/ null
        if (lista->fim == pNodo)// se a lista possui apenas um unico elemento
        {
            lista->fim = NULL;
        }
        else // a lista possui + de 1 elem
        {
            lista->inicio->ant = NULL;
        }
        free(pNodo);
        lista->n--;
        return SUCESSO;
    }
}
/*
incluiNoFim
E/S: Uma lista
Entrada: um dado do tipo Dado
Retorno: Código de erro: SUCESSO ou
FALTOU_MEMORIA
Descrição: Inclui o dado na última posição da lista.
*/
int incluiNoFim(ListaDE *lista, Dados dados)
{
    Nodo *pNodo;
    pNodo = (Nodo *)malloc(sizeof(Nodo));

    if (pNodo == NULL) // erro ao alocar o nodo na mem
    {
        return FALTOU_MEMORIA;
    }
    pNodo->info = dados; //copio os dados p o nNodo q criei
    pNodo->ant = lista->fim; //vai executar em ambos os casos: lista vazia e ja com elem// o campo ant de pNodo aponta para onde lista->fim esta apontando. se a lista estiver vazia pNodo->ant vai apontar p onde lista->fim esta apontando ou seja p null// se ja possuir elem pNodo ant aponta o o atual ultimo nodo q lista->fim aponta
    if (estaVazia(lista))//caso a lista vazia inserir nodo no inicio
    {
        lista->inicio = pNodo; //o inicio da lista aponta p o novo pNodo
        //lista->fim = pNodo;//removido p o final da condicional
    }
    else // se a lista já estiver com elem
    {
        lista->fim->prox = pNodo; //o campo prox do ult elem apontado por lista->fim aponta p o novo pNodo
    }
    lista->fim = pNodo; //lista->fim deixa de apontar para o ex-ultimo nodo e passa apontar o o novo ult
    lista->n++;// incremento do tamanho da lista
    return SUCESSO;
}
/*
excluiDoFim
E/S: Uma lista.
Saída: O dado armazenado na última posição da lista.
Retorno: Código de erro: SUCESSO ou LISTA_VAZIA.
Descrição: Exclui o nodo armazenado na última posição da lista.
*/
int excluiDoFim(ListaDE *lista, Dados *dados)
{
    Nodo *pNodo;

    if (estaVazia(lista))
    {
        return LISTA_VAZIA;
    }
    else
    {
        pNodo = lista->inicio;
        while (pNodo->prox != NULL)
        {
            pNodo = pNodo->prox;
        }
        if (pNodo == lista->inicio) //possui 1 elem na lista
        {
            *dados = pNodo->info;
            lista->inicio = pNodo->prox; //lista->inicio aponta p onde pNodo->prox aponta ou seja p null
            // lista->fim = NULL;//apenas 1 nodo na lista nao preciso deixa-la dupla encad. pq ñ vou usar o camp ant de pNodo pNodo->ant=null
        }
        else //possui + elem na lista. exclui o ultimo
        {
            *dados = pNodo->info;
            pNodo->ant->prox = pNodo->prox;
            lista->fim = pNodo->ant;
        }
        free(pNodo);
        lista->n--;
        return SUCESSO;
    }
}
/*incluiDepois
E/S: Uma lista
Entrada: Um código
Entrada: O dado que será incluído na lista DEPOIS
daquele que possui o código passado como
argumento.
Retorno: SUCESSO, CODIGO_INEXISTENTE ou
FALTOU_MEMORIA.
Descrição: Inclui o dado antes do nodo que possui
o código passado como argumento.
*/
int incluiDepois(ListaDE *lista, Dados dados, int cod)
{
    Nodo *pNodo, *pAux;
    pNodo = (Nodo *)malloc(sizeof(Nodo));

    if (pNodo == NULL) //erro de alocacao de mem
    {
        return FALTOU_MEMORIA;
    }
    if (estaVazia(lista))
    {
        return LISTA_VAZIA;
    }
    pAux = lista->inicio;
    while (pAux != NULL && pAux->info.cod != cod)
    {
        pAux = pAux->prox;
    }
    if (pAux == NULL)
    {
        return CODIGO_INEXISTENTE;
    }
    pNodo->info = dados;
    pNodo->prox = pAux->prox;
    pAux->prox = pNodo;
    pNodo->ant = pAux;
    lista->n++;
    return SUCESSO;
}
/*
excluiNodo
E/S: Uma lista
Entrada: Um código
Saída: O dado do nodo que contém o código passado como
argumento.
Retorno: SUCESSO, CODIGO_INEXISTENTE
Descrição: Exclui o nodo que possui o código passado como argumento
*/
int excluiNodo(ListaDE *lista, Dados *dados, int cod)
{
    Nodo *pNodo;
    pNodo = lista->inicio;
    if (estaVazia(lista)) //lista->inicio == NULL
    {
        return LISTA_VAZIA;
    }
    while (pNodo != NULL && pNodo->info.cod != cod)
    {
        pNodo = pNodo->prox;
    }
    if (pNodo == NULL)
    {
        return CODIGO_INEXISTENTE;
    }
    *dados = pNodo->info;
    if (pNodo == lista->inicio) //caso 1: remove no inicio
    {
        lista->inicio = pNodo->prox; //lista->inicio aponta para onde pNodo->prox aponta ou seja p null
    }
    else if (lista->fim == pNodo) //caso 2: remove ultimo nodo
    {
        pNodo->ant->prox = pNodo->prox;
        lista->fim = pNodo->ant;
    }
    else // caso 3: remove o meio
    {
        pNodo->ant->prox = pNodo->prox;
        pNodo->prox->ant = pNodo->ant;
    }
    free(pNodo);
    lista->n--;
    return SUCESSO;
}
/*
consultaPorCodigo
Entrada: Uma lista
Entrada: Um código.
Saída: O dado que possui o código informado.
Retorno: SUCESSO ou CODIGO_INEXISTENTE
*/
int consultaPorCodigo(ListaDE *lista, Dados *dados, int consultaCod)
// percorrer nodo por nodo ate o fim procurando o codigo
{
    Nodo *pNodo;
    pNodo = lista->inicio;
    while (pNodo != NULL && pNodo->info.cod != consultaCod) //percorre a lista enquanto nao achar o cod
    {
        pNodo = pNodo->prox;
    }
    if (pNodo == NULL) //chegou no fim nao achou
    {
        return CODIGO_INEXISTENTE;
    }
    *dados = pNodo->info; //dado retornado ao ser achado no while
    return SUCESSO;
}
