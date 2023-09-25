/*
 * funcoes.c
 *
 *  Created on: 15 de set. de 2023
 *      Author: fernando-afonso
 */

#include <stdio.h>
#include <stdlib.h>
#include "cabecalho.h"

void cria(LISTA* lista){
	//O ponteiro primeiro da lista recebe uma alocacao do tipo PONT(Apontador para a celula), do tamanho de uma celula;
	lista->primeiro = (PONT)malloc(sizeof(CELULA));
	//O primeiro ultimo recebe o mesmo valor da primeira, ou seja, uma alocacao de memoria.
	lista->ultimo = lista->primeiro;
	//Como o primeiro (e o ultimo) é um apontamento, a celula nova inicialmente nao aponta para ninguem, fato que depois
	//sera mudado.
	lista->primeiro->prox = NULL;
}

//A funcao verifica se o primeiro e o ultimo da lista tem o mesmo valor, se tiver, ela esta vazia e retorna 0, senao,
//tem valor e retorna -1.
int vazia(LISTA lista){
	return (lista.primeiro == lista.ultimo);
}

//Insere no final da lista
int insere(ITEM x, LISTA* lista){
	//E criada uma celula para o ultimo vetor, apontada pelo ultimo da lista;
	lista->ultimo->prox = (PONT)malloc(sizeof(CELULA));
	lista->ultimo = lista->ultimo->prox;
	lista->ultimo->item = x;
	lista->ultimo->prox = NULL;
	return 0;
}

int retira(int elemento, LISTA *lista, ITEM *item){
	//Variaveis auxiliares do tipo PONT
	PONT p, q;

	//A primeira variavel auxiliar receve o valor do primeiro da lista.
	p = lista->primeiro;

	//Enquanto o proximo do primeiro da lista for diferente de nulo, sera percorrido.
	while(p->prox != NULL){

		//Se o item de algum dos proximos do primeiro tiver a chave do item correspondente ao elemento que queremos,
		//faremos o que tiver de fazer:
		if(p->prox->item.chave == elemento){

			//O ponteiro q recebe o proximo da celula encontrada;
			q = p->prox;

			//A partir disso, o item da celula encontrada se torna o item da proxima celula;
			*item = q->item;

			//Assim como a celula encontrada se torna a proxima celula.
			p->prox = q->prox;

			//Caso em algum momento a proxima celula seja nula, ou seja, a ulima celula, setamos o valor da ultima da lista
			//igual ao valor da primeira que esta em p.
			if(p->prox == NULL){
				lista->ultimo = p;
			}

			//Assim, liberamos o ponteiro auxiliar q e retornamos 0 como sucesso.
			free(q);
			return 0;
		}
		//Caso nao tenhamos encontrado ainda o elemento com a chave, pulamos para a proxima celula.
		p = p->prox;
	}
	//Se nao entrar no while, pois esta vazia ou ha erro, retornamos -1.
	return -1;
}

void imprime(LISTA lista){
	//Criamos um ponteiro auxiliar;
	PONT aux;

	//Este ponteiro recebe o proximo do primeiro da lista;
	aux = lista.primeiro->prox;

	//Enquando houver valor no auxiliar, printaremos na tela e em seguida pularemos para o proximo,
	//ate chegar no NULL que representa o fim da lista.
	while(aux != NULL){
		printf("%d\n", aux->item.chave);
		aux = aux->prox;
	}
}
