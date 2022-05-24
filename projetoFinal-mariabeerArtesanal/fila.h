#ifndef fila_H
#define fila_H

#define SUCESSO 0
#define FILA_VAZIA 1
#define CODIGO_INEXISTENTE 2

/*============= DEFINICOES DE TIPOS E PROTOTIPOS DAS FUNCOES ===========*/

// DEFINE OS DADOS DA FILA
typedef struct _beer
{
    char marca[255];
    char estilo[255];
    char embalagem[255];
    int volume;
    int unid;

} Beer;

typedef struct _lote
{
    int lote;
    int dia, mes, ano;
    int val;

} Lote;

// DEFINE OS NODOS DA FILA
typedef struct nodo Nodo;

typedef struct nodo
{
    Beer info;
    Lote dados;
    Nodo *prox; 
} Nodo;

// DEFINE A FILA
typedef struct _fila
{
    Nodo *inicio;
    Nodo *fim;
    int tam;
} FilaProducao;

// PROTOTIPOS DAS FUNCOES
void criarFila(FilaProducao *alocarFila);
int menuPrincipal();
int filaVazia(FilaProducao *filaLote);
int inserir(Beer info, Lote dados, FilaProducao *filaLote);
void exibeFila(FilaProducao filaLote);
int retirar(Beer *info, Lote *dados, FilaProducao *filaLote);
int quantidadeDeNodos(FilaProducao filaLote);
int consultaInicio(Lote *dados, Beer *info, FilaProducao *filaLote);
int consultaPorCodigo(Lote *dados, Beer *info, int cod, FilaProducao *filaLote);

#endif