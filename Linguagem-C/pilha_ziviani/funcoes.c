/*
 * funcoes.c
 *
 *  Created on: 15 de set. de 2023
 *      Author: fernando-afonso
 */

#include <stdio.h>
#include <stdlib.h>
#include "header.h"

//Cria a pilha, o fundo e topo sao alocados no tipo ponteiro para celula.
void cria(PILHA * pilha){

	pilha->topo = (PONT)malloc(sizeof(CELULA));
	pilha->fundo = pilha->topo;
	pilha->topo->prox = NULL;
	pilha->tamanho = 0;

}

//Confere se o topo e igual ao fundo. Se sim, esta vazia.
int vazia(PILHA pilha){
	return (pilha.topo == pilha.fundo);
}

//Insere uma nova celula no inicio da lista, esta servira como cabecalho. O antigo cabecalho
//e preenchido com o item recebido e o tamanho e atualizado.
int push(PILHA* pilha, ITEM item){
	PONT aux;

	aux = (PONT)malloc(sizeof(CELULA));
	pilha->topo->item = item;
	aux->prox = pilha->topo;
	pilha->topo = aux;
	pilha->tamanho++;
	return 0;

}

//Retira-se o elemento cabecalho e a lista->topo se torna o novo cabecalho.
int pop(PILHA *pilha, ITEM *item){
	PONT q;

	if(vazia(*pilha)){
		return -1;
	}

	q = pilha->topo;
	pilha->topo = q->prox;
	*item = q->prox->item;
	free(q);
	pilha->tamanho--;
	return 0;
}

//Recupera o item no topo da pilha sem desempilhar.
int look(PILHA *pilha, ITEM *item){

	if(vazia(*pilha)){
		return -1;
	}
	*item = pilha->topo->prox->item;
	return 0;

}

//Retorna o tamanho da pilha.
int tamanho(PILHA pilha){
	return pilha.tamanho;
}
