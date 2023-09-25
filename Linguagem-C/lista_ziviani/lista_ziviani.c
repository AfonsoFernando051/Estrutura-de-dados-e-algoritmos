/*
 ============================================================================
 Name        : lista.c
 Author      : Fernando
 Version     :
 Copyright   : Your copyright notice
 Description : Hello World in C, Ansi-style
 ============================================================================
 */

#include <stdio.h>
#include <stdlib.h>
#include "cabecalho.h"

int main(void) {
	FILE *arq;
	LISTA lista;
	ITEM item;
	int i;

	//Criacao da lista
	cria(&lista);

	//Lê e insere
	arq = fopen("arq.txt","r");
	while(fscanf(arq, "%d", "r", &i) != EOF){
		item.chave = i;
		if(insere(item, &lista) == -1){
			printf("Erro na insercao de %d\n", i);
		}
	}
	//Imprime a lista criada
	imprime(lista);

	while(!vazia(lista)){
		printf("Favor informar o item a retirar");
		scanf("%d", &i);

		if(i == -1){
			break;
		}

		if(retira(i, &lista, &item) == -1){
			printf("Elemento nao existe na lista.\n");
		}else{
			printf("Elemento retirado.\n");
			imprime(lista);
		}
	}

	return 0;
}
