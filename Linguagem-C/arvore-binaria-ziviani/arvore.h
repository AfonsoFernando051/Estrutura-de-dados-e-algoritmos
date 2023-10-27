#define ARVORE_H

typedef struct{
    int chave;
}ITEM;

typedef struct NO_TAG *PONT;

typedef struct NO_TAG{
    ITEM item;
    PONT esq, dir;
}NO;

typedef PONT ARVORE;

void menu();
void criar(ARVORE *arv);
int pesquisar(ITEM *item, PONT *p);
int inserir(ITEM, PONT *p);
int retirar(ITEM item, PONT *p);
void percorreIn(PONT p);
void percorrePre(PONT p);
void percorrePos(PONT p);