
typedef struct CELULA_TAG *PONT;

typedef struct{
    int chave;
}ITEM;

typedef struct CELULA_TAG{
    ITEM item;
    PONT prox;
}CELULA;

typedef struct{
    PONT primeira, ultima;
}FILA;

void criar(FILA *fila);
int push(FILA *fila, ITEM x);
int vazia(FILA fila);
void imprime(FILA fila);
int look(FILA *fila, ITEM *item);