/*
 * cabecalho.h
 *
 *  Created on: 25 de set. de 2023
 *      Author: fernando-afonso
 */

#ifndef CABECALHO_H_
#define CABECALHO_H_

//Definimos o tamanho maximo do array;
#define MAXTAM  20  /* Altere de acordo com seus testes */
//Definimos o tipo do conteudo de Item;
typedef long CHAVE;
//Criamos a struct de ITEM, que tem como conteudo a CHAVE do tipo long;
typedef struct ITEM_TAG {
	CHAVE chave;
    /* Outros componentes */
} ITEM;
//Definimos um array do tipo ITEM com nome de VETOR e tamanho MAXTAM = 200
typedef ITEM VETOR[MAXTAM];
//Prototipo para funcao insertion-sort, pega o array que queremos e o tamanho do mesmo
void insercao(ITEM *vetor, int tamanho);

#endif /* CABECALHO_H_ */
