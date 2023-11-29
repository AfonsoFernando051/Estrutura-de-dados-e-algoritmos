#include <stdio.h>
#include <string.h>
#include <stdlib.h>

typedef char CHAVE[21];

typedef struct ITEM {
    CHAVE nome;
    double preco;
    struct ITEM* esquerda;
    struct ITEM* direita;
} ITEM;

ITEM* criar_no(CHAVE chave, double preco) {
    ITEM* novo_item = (ITEM*)malloc(sizeof(ITEM));
    if (novo_item == NULL) {
        fprintf(stderr, "Erro ao alocar memória.\n");
        exit(1);
    }
    strcpy(novo_item->nome, chave);
    novo_item->preco = preco;
    novo_item->esquerda = NULL;
    novo_item->direita = NULL;
    return novo_item;
}

ITEM* inserir_arvore(ITEM* raiz, CHAVE chave, double preco) {
    if (raiz == NULL) {
        return criar_no(chave, preco);
    }

    int comparacao = strcmp(chave, raiz->nome);

    if (comparacao < 0) {
        raiz->esquerda = inserir_arvore(raiz->esquerda, chave, preco);
    } else if (comparacao > 0) {
        raiz->direita = inserir_arvore(raiz->direita, chave, preco);
    } else {
        // Tratar caso em que a chave já existe (pode ser substituído ou ignorado)
        // Aqui, por simplicidade, estamos ignorando itens com chaves iguais.
        // Caso deseje substituir, pode-se atualizar o valor da chave.
        printf("Item com chave duplicada: %s\n", chave);
    }

    return raiz;
}

double buscar_preco_arvore(ITEM* raiz, CHAVE chave) {
    if (raiz == NULL) {
        // Item não encontrado, retornar preço 0
        return 0.0;
    }

    int comparacao = strcmp(chave, raiz->nome);

    if (comparacao == 0) {
        return raiz->preco;
    } else if (comparacao < 0) {
        return buscar_preco_arvore(raiz->esquerda, chave);
    } else {
        return buscar_preco_arvore(raiz->direita, chave);
    }
}

void liberar_arvore(ITEM* raiz) {
    if (raiz != NULL) {
        liberar_arvore(raiz->esquerda);
        liberar_arvore(raiz->direita);
        free(raiz);
    }
}

void imprimir_arvore(ITEM* raiz) {
    if (raiz != NULL) {
        imprimir_arvore(raiz->esquerda);
        printf("Chave: %s, Preço: %.2f\n", raiz->nome, raiz->preco);
        imprimir_arvore(raiz->direita);
    }
}

int main() {
    ITEM* arvore = NULL;

    // Exemplo de uso:
    arvore = inserir_arvore(arvore, "item1", 10.99);
    arvore = inserir_arvore(arvore, "item2", 5.49);
    arvore = inserir_arvore(arvore, "item3", 8.99);

    // Imprimir a árvore (percurso em ordem)
    imprimir_arvore(arvore);

    // Buscar preço por chave
    printf("Preço de item2: %.2f\n", buscar_preco_arvore(arvore, "item2"));

    // Libera a memória da árvore
    liberar_arvore(arvore);

    return 0;
}
