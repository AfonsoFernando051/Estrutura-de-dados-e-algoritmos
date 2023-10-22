#include <stdio.h>
#include <stdlib.h>
#include "FilaLyb.h"

void criar(FILA *fila){
    fila->primeira = (PONT)malloc(sizeof(CELULA));
    fila->ultima = fila->primeira;
    fila->primeira->prox = NULL;
}

int push(FILA *fila, ITEM x){
    fila->ultima->prox = (PONT)malloc(sizeof(CELULA));
    fila->ultima = fila->ultima->prox;
    fila->ultima->item = x;
    fila->ultima->prox = NULL;

    return 0;
}

int vazia(FILA fila){
    return fila.primeira == fila.ultima;
}

int pop(FILA *fila, ITEM *item){

    if(vazia(*fila)){
        printf("A fila esta vazia");
        return -1;
    }

    PONT q;
    q = fila->primeira;
    fila->primeira=q->prox;
    *item = q->prox->item;
    free(q);
    return 0;
}

void imprime(FILA fila){
    if(vazia(fila)){
		return -1;
	}
	PONT aux;

	aux = fila.primeira->prox;
    
	while(aux != NULL){
		printf("%d ", aux->item.chave);
		aux = aux->prox;
	}
}

int look(FILA *fila, ITEM *item){
	if(vazia(*fila)){
		return -1;
	}
	*item = fila->primeira->prox->item;
	return 0;
}

int main(void){
    FILA fila;
    criar(&fila);
    ITEM item;

    // Adicionando items na fila.
    for(int i = 0; i < 10; i++){
        item.chave = i;
        if(push(&fila, item) == -1){
            printf("Erro");
        }
    }

    printf("\nItens empilhados: \n");
    imprime(fila);

    look(&fila, &item);
    printf("\nRemovendo primeiro empilhado: %d\n", item.chave);
    if(pop(&fila, &item) == -1){
        printf("Erro");
    }

    printf("\nElementos com o primeiro desempilhado: \n");
    imprime(fila);

    return 0;
}