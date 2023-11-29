#include <stdio.h>
#include <string.h>
#include <stdlib.h>

#define TABLE_SIZE 100

typedef char CHAVE[21];

typedef struct {
    CHAVE nome;
    double preco;
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

    while (tabela->tabela[indice] != NULL) {
        indice = (indice + 1) % TABLE_SIZE;
    }

    tabela->tabela[indice] = novo_item;
}

void remover_item(TABELA_HASH* tabela, CHAVE chave) {
    int indice = hash(chave);

    while (tabela->tabela[indice] != NULL) {
        if (strcmp(tabela->tabela[indice]->nome, chave) == 0) {
            free(tabela->tabela[indice]);
            tabela->tabela[indice] = NULL;
            return;
        }
        indice = (indice + 1) % TABLE_SIZE;
    }
}

double encontrar_preco(TABELA_HASH* tabela, CHAVE chave) {
    int indice = hash(chave);

    while (tabela->tabela[indice] != NULL) {
        if (strcmp(tabela->tabela[indice]->nome, chave) == 0) {
            return tabela->tabela[indice]->preco;
        }
        indice = (indice + 1) % TABLE_SIZE;
    }

    return -1; // Item não encontrado
}

void alterar_preco(TABELA_HASH* tabela, CHAVE chave, double novo_preco) {
    int indice = hash(chave);

    while (tabela->tabela[indice] != NULL) {
        if (strcmp(tabela->tabela[indice]->nome, chave) == 0) {
            tabela->tabela[indice]->preco = novo_preco;
            return;
        }
        indice = (indice + 1) % TABLE_SIZE;
    }
}

void liberar_tabela(TABELA_HASH* tabela) {
    for (int i = 0; i < TABLE_SIZE; i++) {
        if (tabela->tabela[i] != NULL) {
            free(tabela->tabela[i]);
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
