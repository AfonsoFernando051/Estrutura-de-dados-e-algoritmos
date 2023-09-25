/*
 ============================================================================
 Name        : Merge-Sort-c.c
 Author      : Fernando
 Version     :
 Copyright   : Your copyright notice
 Description : Hello World in C, Ansi-style
 ============================================================================
 */

#include <stdio.h>
#include <stdlib.h>
#include "cabecalho.h"
void ordena(VETOR v, int esquerda, int meio, int direita){
	int i, j, k;
    int n1 = meio - esquerda + 1;
    int n2 = direita - meio;

    // Cria matrizes temporárias
    VETOR tempEsquerda, tempDireita;

    // Copia os dados para as matrizes temporárias tempEsquerda[] e tempDireita[]
    for (i = 0; i < n1; i++) {
        tempEsquerda[i] = v[esquerda + i];
    }
    for (j = 0; j < n2; j++) {
        tempDireita[j] = v[meio + 1 + j];
    }

    // Mescla as matrizes temporárias de volta em vet[esquerda..direita]
    i = 0;
    j = 0;
    k = esquerda;
    while (i < n1 && j < n2) {
        if (tempEsquerda[i].chave <= tempDireita[j].chave) {
            v[k++] = tempEsquerda[i++];
        } else {
            v[k++] = tempDireita[j++];
        }
    }

    // Copia os elementos restantes de tempEsquerda[], se houver algum
    while (i < n1) {
        v[k++] = tempEsquerda[i++];
    }

    // Copia os elementos restantes de tempDireita[], se houver algum
    while (j < n2) {
        v[k++] = tempDireita[j++];
    }
}

void mergeSort(VETOR v, int esquerda, int direita) {
	//Se o tamanho do array for menor que 1, entao ja esta ordenado;
	if(esquerda < direita){
		//A metade do array e o tamanho total divido por 2;
		int meio = esquerda + (direita - esquerda)/2;

		//Funcoes recursivas que ordenam
		mergeSort(v, esquerda, meio);
		mergeSort(v, meio + 1, direita);

		//Funcao que ordena dois arrays em um so;
		ordena(v, esquerda, meio, direita);
	}
}

int main(void) {

	//Criamos vetor principal;
	VETOR v;
 	printf("Vetor desordenado:\n");

	//Adicionamos valores em todo o array;
	for(int i = 0; i < MAXTAM; i++){
		v[i].chave = (rand() % 10) * i;
	}

	//Descobrimos o tamanho do array a partir desta operacao;
	int n = sizeof(v)/sizeof(ITEM);

	//Chamamos a funcao que ordena o array;
	mergeSort(v, 0, n - 1);

 	printf("Vetor ordenado:\n");
    for (int i = 0; i < MAXTAM; i++) {
        printf("%ld ", v[i].chave);
    }
	return 0;
}
