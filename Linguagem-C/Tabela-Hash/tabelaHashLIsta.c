#include <stdio.h>
#include <string.h>
#include <stdlib.h>

#define TABLE_SIZE 100

typedef char CHAVE[21];

typedef struct ITEM {
    CHAVE nome;
    double preco;
    struct ITEM* proximo;
} ITEM;

typedef struct {
    ITEM* tabela[TABLE_SIZE];
} TABELA_HASH;

TABELA_HASH* criar_tabela() {
    TABELA_HASH* tabela = (TABELA_HASH*)malloc(sizeof(TABELA_HASH));
    for (int i = 0; i < TABLE_SIZE; i++) {
        tabela->tabela[i] = NULL;
    }
    return tabela;
}

int hash(CHAVE chave) {
    int soma = 0;
    for (int i = 0; chave[i] != '\0'; i++) {
        soma += chave[i];
    }
    return soma % TABLE_SIZE;
}

void inserir_item(TABELA_HASH* tabela, CHAVE chave, double preco) {
    int indice = hash(chave);

    ITEM* novo_item = (ITEM*)malloc(sizeof(ITEM));
    strcpy(novo_item->nome, chave);
    novo_item->preco = preco;
    novo_item->proximo = tabela->tabela[indice];

    tabela->tabela[indice] = novo_item;
}

void remover_item(TABELA_HASH* tabela, CHAVE chave) {
    int indice = hash(chave);
    ITEM* atual = tabela->tabela[indice];
    ITEM* anterior = NULL;

    while (atual != NULL) {
        if (strcmp(atual->nome, chave) == 0) {
            if (anterior != NULL) {
                anterior->proximo = atual->proximo;
            } else {
                tabela->tabela[indice] = atual->proximo;
            }
            free(atual);
            return;
        }
        anterior = atual;
        atual = atual->proximo;
    }
}

double encontrar_preco(TABELA_HASH* tabela, CHAVE chave) {
    int indice = hash(chave);
    ITEM* atual = tabela->tabela[indice];

    while (atual != NULL) {
        if (strcmp(atual->nome, chave) == 0) {
            return atual->preco;
        }
        atual = atual->proximo;
    }

    return -1; // Item não encontrado
}

void alterar_preco(TABELA_HASH* tabela, CHAVE chave, double novo_preco) {
    int indice = hash(chave);
    ITEM* atual = tabela->tabela[indice];

    while (atual != NULL) {
        if (strcmp(atual->nome, chave) == 0) {
            atual->preco = novo_preco;
            return;
        }
        atual = atual->proximo;
    }
}

void liberar_tabela(TABELA_HASH* tabela) {
    for (int i = 0; i < TABLE_SIZE; i++) {
        ITEM* atual = tabela->tabela[i];
        while (atual != NULL) {
            ITEM* proximo = atual->proximo;
            free(atual);
            atual = proximo;
        }
    }
    free(tabela);
}

int main() {
    TABELA_HASH* tabela = criar_tabela();

    // Exemplo de uso:
    inserir_item(tabela, "item1", 10.99);
    inserir_item(tabela, "item2", 5.49);
    inserir_item(tabela, "item3", 8.99);

    printf("Preço do item2: %.2f\n", encontrar_preco(tabela, "item2"));
    alterar_preco(tabela, "item2", 6.99);
    printf("Novo preço do item2: %.2f\n", encontrar_preco(tabela, "item2"));

    remover_item(tabela, "item1");

    liberar_tabela(tabela);

    return 0;
}
