/*
 ============================================================================
 Name        : LLRB.c
 Author      : Fernando Afonso
 Version     :
 Copyright   : Your copyright notice
 Description : Hello World in C, Ansi-style
 ============================================================================
 */

#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include "LLRB.h"

// Cria um node
node* criar(int data, bool cor)
{
    node *novoNode = (node *) malloc(sizeof(node));
    novoNode -> esq = NULL;
    novoNode -> dir = NULL;
    novoNode -> data = data;
    novoNode -> cor = true;
    novoNode -> wasRemoved = false;
    return novoNode;
}

// Rotaciona a esquerda
node* rotateLeft(node* novoNode)
{
    printf("Rotaciona a esquerda\n");
    node *nodeFilho = novoNode -> dir;
    node *filhoEsq = nodeFilho -> esq;

    nodeFilho -> esq = novoNode;
    novoNode -> dir = filhoEsq;

    return nodeFilho;
}

// Rotaciona a direita
node* rotateRight(node* novoNode)
{
    printf("Rotaciona a direita\n");
    node *nodeFilho = novoNode -> esq;
    node *filhoDir =  nodeFilho -> dir;

    nodeFilho -> dir = novoNode;
    novoNode -> esq = filhoDir;

    return nodeFilho;
}

// Confere se é vermelho
int eh_vermelho(node *novoNode)
{
    if (novoNode == NULL)
       return 0;
    return (novoNode -> cor == true);
}

// Troca as cores
void mudarCor(node *node1, node *node2)
{
    bool temp = node1 -> cor;
    node1 -> cor = node2 -> cor;
    node2 -> cor = temp;
}

// Inserir
node* inserir(node* novoNode, int data)
{
    if (novoNode == NULL)
        return criar(data, false);

    if (data < novoNode -> data)
        novoNode -> esq = inserir(novoNode -> esq, data);

    else if (data > novoNode -> data)
        novoNode -> dir = inserir(novoNode -> dir, data);

    else
        return novoNode;

    if (eh_vermelho(novoNode -> dir) && !eh_vermelho(novoNode -> esq))
    {
        novoNode = rotateLeft(novoNode);
        mudarCor(novoNode, novoNode -> esq);
    }

    if (eh_vermelho(novoNode -> esq) && eh_vermelho(novoNode -> esq -> esq))
    {
        novoNode = rotateRight(novoNode);
        mudarCor(novoNode, novoNode -> dir);
    }

    if (eh_vermelho(novoNode -> esq) && eh_vermelho(novoNode -> dir))
    {
        novoNode -> cor = !novoNode -> cor;
        novoNode -> esq -> cor = false;
        novoNode -> dir -> cor = false;
    }

    return novoNode;
}

void print(node *node)
{
    if (node)
    {
        print(node -> esq);
		if(node -> wasRemoved == false){
			printf("%d ", node -> data);
		}
        print(node -> dir);
    }
}

void pesquisaNode(node *node, int valor)
{
	if(node)
	{
		pesquisaNode(node->esq, valor);
		if(node->data == valor){
			printf("\nValor %i encontrado\n", valor);
		}
		pesquisaNode(node->dir, valor);
	}
}

void removeNode(node *node, int valor)
{
	if(node)
	{
		removeNode(node->esq, valor);
		if(node->data == valor){
			node -> wasRemoved = true;
			printf("Valor %i removido\n", valor);
		}
		removeNode(node->dir, valor);
	}
}

int main()
{
    node *raiz = NULL;

    raiz = inserir(raiz, 10);
    raiz -> cor = false;

    raiz = inserir(raiz, 15);
    raiz -> cor = false;

    raiz = inserir(raiz, 20);
    raiz -> cor = false;

    raiz = inserir(raiz, 5);
    raiz -> cor = false;

    raiz = inserir(raiz, 50);
    raiz -> cor = false;

    raiz = inserir(raiz, 25);
    raiz -> cor = false;

    print(raiz);
    pesquisaNode(raiz, 5);
    removeNode(raiz, 20);
    print(raiz);

    return 0;
}