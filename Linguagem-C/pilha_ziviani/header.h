/*
 * header.h
 *
 *  Created on: 15 de set. de 2023
 *      Author: fernando-afonso
 */

#define HEADER_H_

#if !defined(PILHA_H)
#define PILHA_H
//Ponteiro para celula;
typedef struct CELULA_TAG *PONT;

//Item que estara dentro da celula.
typedef struct {
	int chave;
} ITEM;

//Struct da celula que contem o item interno e o ponteiro para a proxima celula.
typedef struct CELULA_TAG{
	ITEM item;
	PONT prox;
}CELULA;

//Struct da pilha que contem os ponteiros para o fundo e topo e o tamanho da celula.
typedef struct{
	PONT fundo, topo;
	int tamanho;
}PILHA;

//Funcao que cria pilha, e entrada a pilha original para ser alterada.
void cria(PILHA* pilha);
//Funcao que verifica se a pilha esta vazia;
int vazia(PILHA pilha);
//Funcao que insere item e cria ultima celula;
int push(PILHA* pilha, ITEM item);
//Funcao que retira item da ultima celula;
int pop(PILHA* pilha, ITEM* item);
//Funcao que permite analisar ultimo elemento no topo da pilha;
int look(PILHA* pilha, ITEM* item);
//Funcao que verifica tamanho da pilha;
int tamanho(PILHA pilha);

#endif /* HEADER_H_ */
