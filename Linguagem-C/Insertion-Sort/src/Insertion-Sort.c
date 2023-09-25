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
	//Criamos esta variavel para auxiliar na posicao da troca de arrays;
	int analise = 0;
	//Percorremos o array de acordo com seu tamanho;
	for(int i = 0; i < tamanho; i++){
		//A variavel auxiliar - analise, vai receber a posicao i em cada iteracao.
		analise = i;
		//Enquanto analise for maior que 0 e necessario para nao compararmos com
		//o elemento inexistente -1, a segunda condicao, e que enquanto a chave do
		//elemento anterior for maior que a atual, faca a condicao.
		//Isto para mudarmos de lugar as posicoes e colocar os menores no inicio.
		while(analise > 0 && vetor[analise].chave < vetor[analise-1].chave){
			//Criamos duas variaveis para acumular o valor da chave do elemento atual,
			//e da chave do elemento anterior ao atual.
			CHAVE chaveAtual = vetor[analise].chave;
			CHAVE chaveAnterior = vetor[analise - 1].chave;

			//Aqui trocamos as posicoes, ja que estando no while, a condicao de que o
			//anterior e maior que o atual e verdadeira.
			vetor[analise].chave = chaveAnterior;
			vetor[analise-1].chave = chaveAtual;

			analise--;
		}
	}

}

int main(void) {
	//Adicionamos o vetor definido no cabecalho, que e do tipo ITEM e tem tamanho de 200.
	VETOR v;

	//Percorremos todo o vetor e adicionamos em cada chave o valor de i
	//multiplicado por um numero aleatorio para ficar desordenado..
	for(int i = 0; i < MAXTAM; i++){
		v[i].chave = (rand() % 10) * i;
	}
	printf("Desordenados\n");

	//Laco for que itera sobre o tamanho do array e printa os itens nao ordernados.
		for(int i = 0; i < MAXTAM; i++){
			printf("%d\n",v[i].chave);
		}
	//Funcao que orderna o array;
	insercao(v, MAXTAM);
	printf("\n");
	printf("Ordenados\n");

	//Laco for que itera sobre o tamanho do array e printa os itens ordernados.
	for(int i = 0; i < MAXTAM; i++){
		printf("%d\n",v[i].chave);
	}

	return 0;
}
