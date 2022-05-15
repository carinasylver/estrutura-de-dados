#include <stdio.h>
#include <stdlib.h>

#define SUCESSO 0
#define PILHA_VAZIA 1
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

typedef struct _pilhaSE
{
    Nodo *topo;
} PilhaSE;

void criaPilha(PilhaSE *pilha);
int empilha(PilhaSE *pilha, Dados dados);
int desempilha(PilhaSE *pilha, Dados *dados);
void exibe(PilhaSE pilha);
int quantidadeDeNodos(PilhaSE pilha);
int pilhaVazia(PilhaSE *pilha);
int consultaTopo(PilhaSE *pilha, Dados dados);

int main(void)
{
    PilhaSE pilha;
    Dados dados;

    int opcao;

    criaPilha(&pilha);

    do
    {
        puts("\n========= MENU =========");
        puts("1.empilha");
        puts("2.desempilha");
        puts("3.quantidade de nodos");
        puts("4.exibe situacao da pilha");
        puts("5.consulta topo");
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

            if (empilha(&pilha, dados) == FALTOU_MEMORIA)
            {
                puts("\nERRO: FALTOU MEMORIA!\n");
            }
            else
            {
                puts("\ndados incluidos com SUCESSO!\n");
            }
            break;
        case 2:
            if (desempilha(&pilha, &dados) == PILHA_VAZIA)
            {
                puts("\nERRO: PILHA VAZIA!\n");
            }
            else
            {
                puts("--------------------------");
                printf("Pilha:\ncodigo: %d e peso %.2f\n\nexcluidos com SUCESSO!!\n", dados.cod, dados.peso);
                puts("--------------------------");
            }
            break;
        case 3:
            printf("\nquantidade de nodos na pilha: %d\n\n", quantidadeDeNodos(pilha));
            break;
        case 4:
            if (pilhaVazia(&pilha) == 1)
            {
                puts("\na pilha esta vazia\n");
            }
            else
            {
                puts("\na pilha possui 1 ou mais nodos\n");
            }
            break;
        case 5:
            if (consultaTopo(&pilha, dados) == PILHA_VAZIA)
            {
                puts("-----------------------------");
                puts("\nERRO: a pilha esta VAZIA\n");
            }
            else
            {
                
                puts("-----------------------------------------------------");
                printf("dados do topo da pilha: cod: %d  peso: %.2f\n\n", dados.cod, dados.peso);
            }
            break;

        } // fim do switch case
        // Após a execução de cada operação deve ser exibida a pilha através da operação exibe.
        exibe(pilha);

    } while (opcao != 0);
    // enquanto for diferente da opcao 0 execute

    return 0;
}
/*
criaPilha
Saída: uma pilha vazia
Retorno: nenhum
Descrição: Cria uma pilha vazia
*/
void criaPilha(PilhaSE *pilha)
{
    pilha->topo = NULL;
}
/*
empilha
E/S: Uma pilha
Entrada: um Dados do tipo Dado
Retorno: Código de erro: SUCESSO ou FALTOU_MEMORIA
Descrição: Empilha o dado na pilha
*/
int empilha(PilhaSE *pilha, Dados dados)
{
    Nodo *pNodo;
    pNodo = (Nodo *) malloc(sizeof(Nodo));

    if (pNodo == NULL) // pNodo == lista vazia
    {
        return FALTOU_MEMORIA; // quando nao tiver memoria suficiente para executar o prog
    }  
    else
    {
        pNodo->info = dados; // nNodo->info recebe o dado que eu quero inserir 
        pNodo->prox = pilha->topo;
        pilha->topo = pNodo;
        return SUCESSO;
    }
}
/*
desempilha
E/S: Uma pilha
Saída: um dado
Retorno: SUCESSO ou PILHA_VAZIA.
Descrição: Desempilha um dado da pilha
*/
int desempilha(PilhaSE *pilha, Dados *dados)
{
    Nodo *pNodo; // pAux=ponteiro auxiliar 

    if (pilhaVazia(pilha))//pilha->topo == NULL
    {
        return PILHA_VAZIA;
    }
    else
    {     
        *dados = pilha->topo->info;  
        pNodo = pilha->topo; // paux é o novo posicao q recebe o dado q esta no topo da pilha
        pilha->topo = pilha->topo->prox; //ou 
        //pilha->topo = pAux->prox
        free(pNodo);
        return SUCESSO;
    }
}
/*
Quantidade de nodos
Exibe a quantidade de nodos existentes na pilha.
 */
int quantidadeDeNodos(PilhaSE pilha)
{
    Nodo *pAux;
    int cont = 0;

    pAux = pilha.topo;
    while (pAux != NULL)
    {
        cont++;
        pAux = pAux->prox;
    }
    return (cont);
}
/*
exibe
Entrada: Uma pilha
Retorno: Nenhum.
Descrição: Exibe todos os nodos da pilha
*/
void exibe(PilhaSE pilha)
{
    Nodo *pAux = pilha.topo;
    puts("--------------------------------------------------------");
    printf("[EnderecoInicio] %p \n", pilha.topo);
     puts("--------------------------------------------------------");
    printf("Exibindo a PILHA ENCADEADA:\n");
    printf("[EnderecoNodo]       [cod] [peso] [EnderecoProxNodo]\n");
    while (pAux != NULL)
    {
        printf("  %p -   %3d  %.2f - %p\n", pAux, pAux->info.cod, pAux->info.peso, pAux->prox);
        puts("--------------------------------------------------------");
        pAux = pAux->prox;
    }
    printf("[EnderecoFim]: NULL\n");
    puts("--------------------------------------------------------");
}
/*
estaVazia
Entrada: Uma pilha.
Retorno: 1 se a pilha está vazia e 0 caso contrário.
*/
int pilhaVazia(PilhaSE *pilha)
{
    if (pilha->topo == NULL)
    {
        return 1; // pilha vazia
    }
    else
    {
        return 0;
    }
}
/*
consultaTopo
Entrada: Uma pilha.
Saída: O dado que está no topo da pilha
Retorno: SUCESSO ou PILHA_VAZIA
*/
int consultaTopo(PilhaSE *pilha, Dados dados)
{
    Nodo *nNodo;
    if (pilhaVazia(pilha))
    {
        return PILHA_VAZIA;
    }
    else
    {
        nNodo = pilha->topo;
        nNodo->info = dados;
        return SUCESSO;
    }
}
