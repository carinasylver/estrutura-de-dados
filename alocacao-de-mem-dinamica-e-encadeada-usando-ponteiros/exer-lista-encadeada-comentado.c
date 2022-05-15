#include <stdio.h>
#include <stdlib.h>

#define SUCESSO 0
#define LISTA_VAZIA 1
#define FALTOU_MEMORIA 2
#define CODIGO_INEXISTENTE 3

typedef struct no Nodo;

// DEFINE OS DADOS DA LISTA ENCADEADA
typedef struct _dados
{
    int cod;
    float peso;
} Dados;

// DEFINE OS NODOS DA LISTA ENCADEADA
typedef struct no
{
    Dados info; /*informacao armazenada*/
    Nodo *prox; /*endereco para o proximo no*/
} Nodo;

// DEFINE A LISTA ENCADEADA
typedef struct _listaSE
{
    Nodo *inicio;
    // Nodo *fim;
} ListaSE;

// DEFINE OS PROTOTIPOS DA FUNCOES
void criaLista(ListaSE *lista);
int incluiNoInicio(ListaSE *lista, Dados dados);
void exibe(ListaSE lista);
int quantidadeDeNodos(ListaSE lista);
int estaVazia(ListaSE *lista);
int excluiDoInicio(ListaSE *lista, Dados *dados);
int incluiNoFim(ListaSE *lista, Dados dados);
int excluiDoFim(ListaSE *lista, Dados *dados);
int incluiDepois(ListaSE *lista, Dados dados, int cod);
int excluiNodo(ListaSE *lista, Dados *dados, int cod);
int consultaPorCodigo(ListaSE *lista, Dados *dados, int consultaCod);

// FUNCAO PRINCIPAL
int main(void)
{
    ListaSE lista;
    Dados dados;
    int opcao, consultaCod, cod, op;

    criaLista(&lista);

    opcao = 1;
    while (opcao != 0)
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
                puts("\ndados incluidos com SUCESSO!\n");
            }
            break;
        case 2:
            exibe(lista);
            break;
        case 3:
            printf("\nquantidade de nodos na lista: %d\n\n", quantidadeDeNodos(lista));
            break;
        case 4:
            if (estaVazia(&lista) == 1)
            {
                puts("\na lista esta vazia\n");
            }
            else
            {
                puts("\na lista possui 1 ou mais nodos\n");
            }
            break;
        case 5:
            if (excluiDoInicio(&lista, &dados) == LISTA_VAZIA)
            {
                puts("\nERRO: LISTA VAZIA!\n");
            }
            else
            {
                puts("--------------------------");
                printf("Lista:\ncodigo: %d e peso %.2f\n\nexcluidos com SUCESSO!!\n", dados.cod, dados.peso);
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
                puts("\ndados incluidos com SUCESSO!\n");
            }
            break;
        case 7:
            if (excluiDoFim(&lista, &dados) == LISTA_VAZIA)
            {
                puts("\nERRO: a lista esta VAZIA\n");
            }
            else
            {
                puts("--------------------------");
                printf("Lista:\ncodigo: %d e peso %.2f\n\nexcluidos com SUCESSO!!\n", dados.cod, dados.peso);
                puts("--------------------------");
            }
            break;
        case 8:
            printf("informe o codigo: ");
            scanf("%d", &consultaCod);

            if (consultaPorCodigo(&lista, &dados, consultaCod) == CODIGO_INEXISTENTE)
            {
                puts("---------------------------");
                puts("ERRO: Codigo informado eh inexistente\n");
            }
            else
            {
                puts("---------------------------");
                puts("Codigo encontrado");
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
                puts("---------------------------");
                puts("\nERRO: faltou MEMORIA");
            }
            else if (op == LISTA_VAZIA)
            {
                puts("\nERRO: a lista esta VAZIA\n");
            }
            else if (op == CODIGO_INEXISTENTE)
            {
                puts("---------------------------");
                puts("\nERRO: codigo informado eh INEXISTENTE. nao foi possivel inserir os dados!!\n");
            }
            else
            {
                puts("\ndados incluidos com SUCESSO!");
            }
            break;
        case 10:
            printf("informe o codigo dos dados para exclusao: ");
            scanf("%d", &cod);
            op = excluiNodo(&lista, &dados, cod);
            if (op == LISTA_VAZIA)
            {
                puts("---------------------------");
                puts("ERRO: a lista esta VAZIA\n");
            }
            else if (op == CODIGO_INEXISTENTE)
            {
                puts("---------------------------");
                puts("ERRO: codigo inexistente\n");
            }
            else
            {
                puts("---------------------------");
                printf("codigo: %d peso: %.2f\ndados excluidos com SUCESSO!\n", dados.cod, dados.peso);
            }
            break;
        } // fim switch case
        if (opcao != 2)
        {
            exibe(lista);
        }
    } // fim while
    return 0;
}
/*
criaLista
Saída: uma lista vazia
Retorno: nenhum
Descrição: Cria uma lista vazia
*/
// funcao q define a lista como vazia
void criaLista(ListaSE *lista)
{
    // a lista esta vazia quando o ponteiro para o inicio da lista aponta para null. ou seja nao aponta para nenhum nó.
    lista->inicio = NULL;
}
/*
incluiNoInicio
E/S: Uma lista
Entrada: um dado do tipo Dado
Retorno: Código de erro: SUCESSO ou FALTOU_MEMORIA
Descrição: Inclui o dado na primeira posição da lista
*/
int incluiNoInicio(ListaSE *lista, Dados dados) 
{
    Nodo *nNodo = (Nodo *)malloc(sizeof(Nodo));

    if (nNodo == NULL)
    {
        return FALTOU_MEMORIA; // quando nao tiver memoria suficiente para alocar nNodo
    }
    else
    {
        nNodo->info = dados;         // novo->info recebe o dado que eu recebi por parametro
        nNodo->prox = lista->inicio; // lista->inicio aponta para o nNodo a ser inserido eo campo prox para null se nao existir mais nodo depois. do contrario o prox aponta p o ex-1º nodo da lista
        lista->inicio = nNodo;       // o inicio da lista aponta sempre p o novo nodo que inseri refazendo o encadeamento
        return SUCESSO;
    }
}
/*
exibe
Entrada: Uma lista
Retorno: Nenhum.
Descrição: Exibe todos os nodos da lista
*/
void exibe(ListaSE lista)
{
    Nodo *pAux = lista.inicio;
    // pAux = lista.inicio;
    puts("--------------------------------------------------------");
    printf("[EnderecoInicio]\n %p\n", lista.inicio);
    puts("--------------------------------------------------------");
    printf("Exibindo a LISTA ENCADEADA:\n");
    printf("[EnderecoNodo]       [cod] [peso] [EnderecoProxNodo]\n");
    while (pAux != NULL)
    {
        printf("  %p -   %3d   %.2f -  %p   \n", pAux, pAux->info.cod, pAux->info.peso, pAux->prox);
        puts("--------------------------------------------------------");
        pAux = pAux->prox;
    }
    printf("[EnderecoFim]: NULL\n");
    puts("--------------------------------------------------------");
}
/*
quantidadeDeNodos
Entrada: Uma lista.
Retorno: A quantidade de nodos existente na lista.
*/
int quantidadeDeNodos(ListaSE lista)
{

    Nodo *pAux = lista.inicio;
    int cont = 0;

    // pAux = lista.inicio;
    while (pAux != NULL)
    {
        cont++;
        pAux = pAux->prox;
    }
    return (cont);
}
/*
estaVazia
Entrada: Uma lista.
Retorno: 1 se a lista está vazia e 0 caso contrário.
*/
int estaVazia(ListaSE *lista)
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
int excluiDoInicio(ListaSE *lista, Dados *dados)
{
    Nodo *nNodo;

    if (estaVazia(lista)) // lista->inicio == NULL
    {
        return LISTA_VAZIA;
    }
    else // ha nodo na lista para excluir
    {
        *dados = lista->inicio->info;
        nNodo = lista->inicio;
        lista->inicio = lista->inicio->prox; // lista.inicio aponta para o prox elem
        // lista->inicio = nNodo->prox //é o mesmo que lista->inicio = lista->inicio->prox
        free(nNodo);
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
int incluiNoFim(ListaSE *lista, Dados dados)
{
    Nodo *nNodo = (Nodo *)malloc(sizeof(Nodo));

    if (nNodo == NULL) // erro ao tentar alocar espaco na mem para o nodo
    {
        return FALTOU_MEMORIA;
    }
    nNodo->info = dados;  // dados que eu irei  inserir
    nNodo->prox = NULL;   // como irei inserir no final da lista o prox elemento sera null
    if (estaVazia(lista)) // lista->inicio == NULL caso a lista estiver vazia inserir no inicio
    {
        lista->inicio = nNodo; // o inicio da lista eh o novo nodo
        return SUCESSO;
    }
    else // se nao for uma lista vazia tenho q percorrer ate achar o ultimo nodo da lista
    {
        Nodo *aux = lista->inicio; // o ponteiro aux vale o inicio da lista
        while (aux->prox != NULL)  // sempre percorro a lista com o aux e nunca com a cabeça da lista(lista->inicio). enquanto o prox elemento for !=null o aux vai receber o nodo seguinte a ele
        {
            aux = aux->prox;
        }
        aux->prox = nNodo; // cheguei no final em null, insiro o novo nodo
        return SUCESSO;
    }
}
/*
excluiDoFim
E/S: Uma lista.
Saída: O dado armazenado na última posição da lista.
Retorno: Código de erro: SUCESSO ou LISTA_VAZIA.
Descrição: Exclui o nodo armazenado na última posição da lista.
*/
int excluiDoFim(ListaSE *lista, Dados *dados)
{
    Nodo *nNodo, *antNodo;

    nNodo = lista->inicio;

    if (estaVazia(lista)) // lista->inicio == NULL
    {
        return LISTA_VAZIA;
    }
    while (nNodo->prox != NULL)
    {
        antNodo = nNodo;     // o nodo ant aponta para nNodo
        nNodo = nNodo->prox; // nNodo recebe o elem seguinte a ele
    }
    if (nNodo == lista->inicio) // eh o inicio da lista? exclui o ultimo e unico nodo
    {
        *dados = lista->inicio->info; // lista->inicio->info aponta para a info do unico nodo
        lista->inicio = nNodo->prox;  // lista->inicio recebe nNodo->prox q passara a apontar para null, tornando o nodo unico
    }
    else
    {
        *dados = antNodo->prox->info; // antNodo->prox aponta para a info do novo ultimo nodo
        antNodo->prox = nNodo->prox;  // antNodo aponta para nNodo e seu prox que passa a ser o ultimo nodo passa a apontar para null
    }
    free(nNodo);
    return SUCESSO;
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
int incluiDepois(ListaSE *lista, Dados dados, int cod) // revisado
{
    Nodo *pNodo, *pAux;
    pNodo = (Nodo *)malloc(sizeof(Nodo));

    if (pNodo == NULL)
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
    // insere entre dois nodos ou fim
    pAux->prox = pNodo; // o campo prox do nodo q p aux esta apontando aponta para o nono nodo nNodo
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
int excluiNodo(ListaSE *lista, Dados *dados, int cod)
{
    Nodo *nNodo, *aux;
    nNodo = lista->inicio;
    if (estaVazia(lista)) // lista->inicio == NULL
    {
        return LISTA_VAZIA;
    }
    while (nNodo != NULL && nNodo->info.cod != cod)
    {
        aux = nNodo;
        nNodo = nNodo->prox;
    }
    if (nNodo == NULL)
    {
        return CODIGO_INEXISTENTE;
    }
    if (nNodo == lista->inicio) // exclusao do 1 nodo do inicio da lista
    {
        *dados = lista->inicio->info; // preservo a informacao q sera excluida para retornar p main os dados excluidos
        lista->inicio = nNodo->prox;  // ou lista->inicio = lista->inicio->prox;
    }
    else
    {                             // exclusao de outra posicao qualquer
        *dados = aux->prox->info; // preservo a informacao q sera excluida para retornar p main os dados excluidos//aux->prox aponta para a info do novo ultimo nodo
        aux->prox = nNodo->prox;
    }
    free(nNodo);
    return SUCESSO;
}
/*
consultaPorCodigo
Entrada: Uma lista
Entrada: Um código.
Saída: O dado que possui o código informado.
Retorno: SUCESSO ou CODIGO_INEXISTENTE
*/
int consultaPorCodigo(ListaSE *lista, Dados *dados, int consultaCod)
{
    Nodo *nNodo;

    nNodo = lista->inicio;
    while (nNodo != NULL)
    {
        if (nNodo->info.cod == consultaCod)
        {
            *dados = nNodo->info;
            return SUCESSO;
        }
        nNodo = nNodo->prox;
    }
    return CODIGO_INEXISTENTE;
}
