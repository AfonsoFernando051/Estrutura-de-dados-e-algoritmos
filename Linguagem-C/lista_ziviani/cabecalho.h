/*
 * cabecalho.h
 *
 *  Created on: 15 de set. de 2023
 *      Author: fernando-afonso
 */

#define CABECALHO_H_


#if !defined(LISTA_H)
#define LISTA_H

/*Ponteiro para a celula*/
typedef struct CELULA_TAG *PONT;

/*Item que armazenará o que queremos na celula*/
typedef struct {
	int chave;
//	Outras coisas
} ITEM;

/*Celula que armazenara os itens e o ponteiro para a proxima celula*/
typedef struct CELULA_TAG {
	ITEM item;
	PONT prox;
}CELULA;

/*LIsta que armazena os ponteiros que apontam para para a celula cabecalho, e o ultimo item da lista*/
typedef struct{
	PONT primeiro, ultimo;
}LISTA;

//Funcao que cria a lista inicial, recebe por referencia para alterar a variavel inicial passada na funcao main;
void cria(LISTA* lista);

//Funcao que verifica se a lista esta vazia, recebe por parametro pois cria uma variavel auxiliar para verificar sem alterar
//a primeira variavel.
int vazia(Lista);

//Funcao que insere um elemento na lista, por referencia na lista que sera alterada e por parametro na variavel que sera inserida
int insere(ITEM item, LISTA* lista);

//Funcao que retira um item na lista. Recebe uma chave para identificar o item por parametro, ja a lista e o item vao por
//referencia para altera os originais.
int retira(int elemento, LISTA* lista, ITEM* item);

//Funcao que imprime a lista e o que tem dentro dela, recebe por parametro pois nao havera alteracoes de fato.
void imprime(LISTA lista);

#endif /* CABECALHO_H_ */
