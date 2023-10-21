/*
 ============================================================================
 Name        : Insertion-sort.c
 Author      : Fernando
 Version     :
 Copyright   : Your copyright notice
 Description : Hello World in C, Ansi-style
 ============================================================================
 */

#include <stdio.h>
#include <stdlib.h>
#include "cabecalho.h"
//Funcao de ordenacao por insercao;
void insercao(ITEM *vetor, int tamanho){
	int analise = 0;
	for(int i = 0; i < tamanho; i++){
		analise = i;
		while(analise > 0 && vetor[analise].chave < vetor[analise-1].chave){
			CHAVE chaveAtual = vetor[analise].chave;
			CHAVE chaveAnterior = vetor[analise - 1].chave;
			vetor[analise].chave = chaveAnterior;
			vetor[analise-1].chave = chaveAtual;

			analise--;
		}
	}

}

int main(void) {
	VETOR v;
	
	for(int i = 0; i < MAXTAM; i++){
		v[i].chave = (rand() % 10) * i;
	}
	printf("Desordenados\n");

	for(int i = 0; i < MAXTAM; i++){
		printf("%d\n",v[i].chave);
	}
	//Funcao que orderna o array;
	insercao(v, MAXTAM);
	printf("\n");
	printf("Ordenados\n");

	for(int i = 0; i < MAXTAM; i++){
		printf("%d\n",v[i].chave);
	}

	return 0;
}
