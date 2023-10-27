#include <stdlib.h>
#include <stdio.h>
#include "arvore.h"

int main(void){

    ARVORE arv;
    ITEM item;
    int opcao = 0;

    menu();

  do{
    printf("\nEscolha uma opcao: \n");
    printf("\n1 - Criar Arvore \n");
    printf("\n2 - Inserir na Arvore \n");
    printf("\n3 - Remover da Arvore \n");
    printf("\n4 - Percorrer Arvore \n");
    printf("\nQualquer outra - Sair\n");
    scanf(" %d", &opcao);

    switch (opcao){
        case 1:
            criar(&arv);
            printf("\nArvore Criada...\n");
            break;
        case 2:
            for(int i = 0; i< 10; i++){
            item.chave = i;
                if(inserir(item, &arv) == -1){
                    printf("Erro na insercao de %d\n", i);
                }
            }

            printf("\nInseridos: \n");
            percorrePre(arv);

            break;
        case 3:
            printf("\nQual item deseja remover: \n");
            scanf("%d", &item.chave);

            if(item.chave == -1){
                printf("\nNao ha itens a remover: \n");
                break;
            }

            if(retirar(item, &arv) == -1){
                printf("\nElemento nao existe na arvore...\n");
            }else{
                printf("\nElemento retirado\n");
                percorreIn(arv);
            }
            break;
        case 4:
            printf("Pre ordem: \n");
            percorrePre(arv);

            printf("Pos ordem: \n");
            percorrePos(arv);
            
            printf("In ordem: \n");
            percorreIn(arv);
        break;
        default:
            printf("Saindo...\n");
            break;
    }
  }while(opcao == 1 || opcao == 2 || opcao == 3 || opcao == 4);

    return 0;
}

void menu(){
    char arte[] =
"███████╗███████╗ █████╗ ██████╗  ██████╗██╗  ██╗\n"
"██╔════╝██╔════╝██╔══██╗██╔══██╗██╔════╝██║  ██║\n"
"███████╗█████╗  ███████║██████╔╝██║     ███████║\n"                                
"╚════██║██╔══╝  ██╔══██║██╔══██╗██║     ██╔══██║\n"                               
"███████║███████╗██║  ██║██║  ██║╚██████╗██║  ██║\n"                               
"╚══════╝╚══════╝╚═╝  ╚═╝╚═╝  ╚═╝ ╚═════╝╚═╝  ╚═╝\n"                               
    "\n"                                                                            
"████████╗██╗  ██╗██████╗ ███████╗███████╗\n"                                      
"╚══██╔══╝██║  ██║██╔══██╗██╔════╝██╔════╝\n"                                      
"   ██║   ███████║██████╔╝█████╗  █████╗\n"                                         
"   ██║   ██╔══██║██╔══██╗██╔══╝  ██╔══╝\n"                                        
"   ██║   ██║  ██║██║  ██║███████╗███████╗\n"                                      
"   ╚═╝   ╚═╝  ╚═╝╚═╝  ╚═╝╚══════╝╚══════╝\n"                                      
"\n"
" ██████╗ ██████╗ ███████╗██████╗  █████╗ ████████╗██╗ ██████╗ ███╗   ██╗███████╗\n"
"██╔═══██╗██╔══██╗██╔════╝██╔══██╗██╔══██╗╚══██╔══╝██║██╔═══██╗████╗  ██║██╔════╝\n"
"██║   ██║██████╔╝█████╗  ██████╔╝███████║   ██║   ██║██║   ██║██╔██╗ ██║███████╗\n"
"██║   ██║██╔═══╝ ██╔══╝  ██╔══██╗██╔══██║   ██║   ██║██║   ██║██║╚██╗██║╚════██║\n"
"╚██████╔╝██║     ███████╗██║  ██║██║  ██║   ██║   ██║╚██████╔╝██║ ╚████║███████║\n"
" ╚═════╝ ╚═╝     ╚══════╝╚═╝  ╚═╝╚═╝  ╚═╝   ╚═╝   ╚═╝ ╚═════╝ ╚═╝  ╚═══╝╚══════╝\n"                                                                                                                                                    
;

    printf("\n%s\n", arte);
}


void criar(ARVORE *arv){
    *arv = NULL;
}

int pesquisa(ITEM *x, PONT *p){
    if(p == NULL){
        return -1;
    }

    if(x->chave < (*p)->item.chave){
        return pesquisa(x, &(*p)->esq);
    }
    if(x->chave > (*p)->item.chave){
        return pesquisa(x, &(*p)->dir);
    }

    *x = (*p)->item;

    return 0;
}

int inserir(ITEM x, PONT *p){
    if(*p == NULL){
        *p = (PONT)malloc(sizeof(NO));
        (*p)->item = x;
        (*p)->esq = NULL;
        (*p)->dir = NULL;
        return 0;
    }

    if(x.chave < (*p)->item.chave){
        return inserir(x, &(*p)->esq);
    }
    if(x.chave > (*p)->item.chave){
        return inserir(x, &(*p)->dir);
    }

    return -1;
}

void antecessor(PONT q, PONT *r){
    if((*r)->dir != NULL){
        antecessor(q, &(*r)->dir);
        return;
    }

    q->item = (*r)->item;
    q = *r;
    *r = (*r)->esq;
    free(q);
}

int retirar(ITEM x, PONT *p){
    PONT aux;

    if(*p == NULL){
        return -1;
    }

    if(x.chave < (*p)->item.chave){
        return retirar(x, &(*p)->esq);
    }
    if(x.chave > (*p)->item.chave){
        return retirar(x, &(*p)->dir);
    }

    if((*p)->dir == NULL){
        aux = *p;
        *p = (*p)->esq;
        free(aux);
        return 0;
    }
    if((*p)->esq == NULL){
        aux = *p;
        *p = (*p)->dir;
        free(aux);
        return 0;
    }

    antecessor(*p, &(*p)->esq);
    return 0;
}

void percorreIn(PONT p){
    if(p != NULL){
        percorreIn(p->esq);
        printf("%d ", p->item.chave);
        percorreIn(p->dir);
    }
}

void percorrePre(PONT p){
    if(p != NULL){
        printf("%d ", p->item.chave);
        percorrePre(p->esq);
        percorrePre(p->dir);
    }
}

void percorrePos(PONT p){
    if(p != NULL){
        percorrePos(p->esq);
        percorrePos(p->dir);
        printf("%d ", p->item.chave);
    }
}