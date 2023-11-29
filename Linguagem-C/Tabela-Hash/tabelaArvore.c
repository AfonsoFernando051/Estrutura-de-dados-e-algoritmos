#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef char CHAVE[21];

typedef struct {
    CHAVE nome;
    double preco;
} ITEM;

// Definir a estrutura para tabela hash com endereçamento aberto
#define TAMANHO_TABELA 100

typedef struct {
    ITEM tabela[TAMANHO_TABELA];
    int tamanho;
} TabelaHashAberta;

// Função para calcular o índice da tabela hash (hash)
int hash(char *chave) {
    int valor = 0;
    for (int i = 0; chave[i] != '\0'; i++) {
        valor += (int)chave[i];
    }
    return valor % TAMANHO_TABELA;
}

// Função para criar um dicionário vazio (tabela hash com endereçamento aberto)
TabelaHashAberta criarTabelaHashAberta() {
    TabelaHashAberta tabela;
    tabela.tamanho = 0;
    for (int i = 0; i < TAMANHO_TABELA; i++) {
        strcpy(tabela.tabela[i].nome, "");
        tabela.tabela[i].preco = 0.0;
    }
    return tabela;
}

// Função para inserir um item no dicionário (tabela hash com endereçamento aberto)
TabelaHashAberta inserirItemTabelaAberta(TabelaHashAberta tabela, ITEM item) {
    int indice = hash(item.nome);
    while (strcmp(tabela.tabela[indice].nome, "") != 0) {
        // Tratar colisões (por exemplo, usando sondagem linear)
        indice = (indice + 1) % TAMANHO_TABELA;
    }
    tabela.tabela[indice] = item;
    tabela.tamanho++;
    return tabela;
}

// Função para buscar e retornar o preço de um item (tabela hash com endereçamento aberto)
double buscarPrecoTabelaAberta(TabelaHashAberta tabela, CHAVE chave) {
    int indice = hash(chave);
    while (strcmp(tabela.tabela[indice].nome, chave) != 0) {
        if (strcmp(tabela.tabela[indice].nome, "") == 0) {
            // Item não encontrado, retornar preço 0
            return 0.0;
        }
        indice = (indice + 1) % TAMANHO_TABELA;
    }
    return tabela.tabela[indice].preco;
}

// Função para alterar o preço de um item (tabela hash com endereçamento aberto)
TabelaHashAberta alterarPrecoTabelaAberta(TabelaHashAberta tabela, CHAVE chave, double novoPreco) {
    int indice = hash(chave);
    while (strcmp(tabela.tabela[indice].nome, chave) != 0) {
        if (strcmp(tabela.tabela[indice].nome, "") == 0) {
            // Item não encontrado, nada a fazer
            return tabela;
        }
        indice = (indice + 1) % TAMANHO_TABELA;
    }
    tabela.tabela[indice].preco = novoPreco;
    return tabela;
}

// Função para remover um item da tabela (tabela hash com endereçamento aberto)
TabelaHashAberta removerItemTabelaAberta(TabelaHashAberta tabela, CHAVE chave) {
    int indice = hash(chave);
    while (strcmp(tabela.tabela[indice].nome, chave) != 0) {
        if (strcmp(tabela.tabela[indice].nome, "") == 0) {
            // Item não encontrado, nada a fazer
            return tabela;
        }
        indice = (indice + 1) % TAMANHO_TABELA;
    }
    strcpy(tabela.tabela[indice].nome, "");
    tabela.tabela[indice].preco = 0.0;
    tabela.tamanho--;
    return tabela;
}

// Definir a estrutura para tabela hash com listas encadeadas
typedef struct NoLista {
    ITEM item;
    struct NoLista *prox;
} NoLista;

typedef struct {
    NoLista *tabela[TAMANHO_TABELA];
} TabelaHashListasEncadeadas;

// Função para criar uma tabela hash com listas encadeadas
TabelaHashListasEncadeadas criarTabelaHashListasEncadeadas() {
    TabelaHashListasEncadeadas tabela;
    for (int i = 0; i < TAMANHO_TABELA; i++) {
        tabela.tabela[i] = NULL;
    }
    return tabela;
}

// Função para inserir um item na tabela hash com listas encadeadas
TabelaHashListasEncadeadas inserirItemTabelaListasEncadeadas(TabelaHashListasEncadeadas tabela, ITEM item) {
    int indice = hash(item.nome);
    NoLista *novoNo = (NoLista *)malloc(sizeof(NoLista));
    if (novoNo == NULL) {
        fprintf(stderr, "Erro ao alocar memória.\n");
        exit(1);
    }
    novoNo->item = item;
    novoNo->prox = tabela.tabela[indice];
    tabela.tabela[indice] = novoNo;
    return tabela;
}

// Função para buscar e retornar o preço de um item na tabela hash com listas encadeadas
double buscarPrecoTabelaListasEncadeadas(TabelaHashListasEncadeadas tabela, CHAVE chave) {
    int indice = hash(chave);
    NoLista *atual = tabela.tabela[indice];
    while (atual != NULL) {
        if (strcmp(atual->item.nome, chave) == 0) {
            return atual->item.preco;
        }
        atual = atual->prox;
    }
    // Item não encontrado, retornar preço 0
    return 0.0;
}

// Função para remover um item da tabela hash com listas encadeadas
TabelaHashListasEncadeadas removerItemTabelaListasEncadeadas(TabelaHashListasEncadeadas tabela, CHAVE chave) {
    int indice = hash(chave);
    NoLista *atual = tabela.tabela[indice];
    NoLista *anterior = NULL;
    while (atual != NULL) {
        if (strcmp(atual->item.nome, chave) == 0) {
            if (anterior == NULL) {
                tabela.tabela[indice] = atual->prox;
            } else {
                anterior->prox = atual->prox;
            }
            free(atual);
            break;
        }
        anterior = atual;
        atual = atual->prox;
    }
    return tabela;
}

// Definir a estrutura para árvore binária de pesquisa
typedef struct NoArvore {
    ITEM item;
    struct NoArvore *esquerda;
    struct NoArvore *direita;
} NoArvore;

// Função para criar um nó na árvore binária de pesquisa
NoArvore *criarNoArvore(ITEM item) {
    NoArvore *novoNo = (NoArvore *)malloc(sizeof(NoArvore));
    if (novoNo == NULL) {
        fprintf(stderr, "Erro ao alocar memória.\n");
        exit(1);
    }
    novoNo->item = item;
    novoNo->esquerda = NULL;
    novoNo->direita = NULL;
    return novoNo;
}

// Função para inserir um item na árvore binária de pesquisa
NoArvore *inserirArvore(NoArvore *raiz, ITEM item) {
    if (raiz == NULL) {
        return criarNoArvore(item);
    }
    int comparacao = strcmp(item.nome, raiz->item.nome);
    if (comparacao < 0) {
        raiz->esquerda = inserirArvore(raiz->esquerda, item);
    } else if (comparacao > 0) {
        raiz->direita = inserirArvore(raiz->direita, item);
    }
    return raiz;
}

// Função para buscar e retornar o preço de um item na árvore binária de pesquisa
double buscarPrecoArvore(NoArvore *raiz, CHAVE chave) {
    if (raiz == NULL) {
        // Item não encontrado, retornar preço 0
        return 0.0;
    }
    int comparacao = strcmp(chave, raiz->item.nome);
    if (comparacao == 0) {
        return raiz->item.preco;
    } else if (comparacao < 0) {
        return buscarPrecoArvore(raiz->esquerda, chave);
    } else {
        return buscarPrecoArvore(raiz->direita, chave);
    }
}

// Função para calcular a altura de uma árvore binária
int calcularAlturaArvore(NoArvore *raiz) {
    if (raiz == NULL) {
        return 0;
    }
    int alturaEsquerda = calcularAlturaArvore(raiz->esquerda);
    int alturaDireita = calcularAlturaArvore(raiz->direita);
    return (alturaEsquerda > alturaDireita) ? (alturaEsquerda + 1) : (alturaDireita + 1);
}

// Função para liberar a memória de uma árvore binária
void liberarArvore(NoArvore *raiz) {
    if (raiz != NULL) {
        liberarArvore(raiz->esquerda);
        liberarArvore(raiz->direita);
        free(raiz);
    }
}

int main() {
    // Testando as operações com a tabela hash com endereçamento aberto
    TabelaHashAberta tabelaHashAberta = criarTabelaHashAberta();

    ITEM item1 = { "item1", 10.0 };
    ITEM item2 = { "item2", 20.0 };

    tabelaHashAberta = inserirItemTabelaAberta(tabelaHashAberta, item1);
    tabelaHashAberta = inserirItemTabelaAberta(tabelaHashAberta, item2);

    printf("Preço de item1: %.2f\n", buscarPrecoTabelaAberta(tabelaHashAberta, "item1"));
    printf("Preço de item2: %.2f\n", buscarPrecoTabelaAberta(tabelaHashAberta, "item2"));

    tabelaHashAberta = alterarPrecoTabelaAberta(tabelaHashAberta, "item1", 15.0);
    printf("Novo preço de item1: %.2f\n", buscarPrecoTabelaAberta(tabelaHashAberta, "item1"));

    tabelaHashAberta = removerItemTabelaAberta(tabelaHashAberta, "item2");
    printf("Preço de item2 após remoção: %.2f\n", buscarPrecoTabelaAberta(tabelaHashAberta, "item2"));

    // Testando as operações com a tabela hash com listas encadeadas
    TabelaHashListasEncadeadas tabelaHashListasEncadeadas = criarTabelaHashListasEncadeadas();

    tabelaHashListasEncadeadas = inserirItemTabelaListasEncadeadas(tabelaHashListasEncadeadas, item1);
    tabelaHashListasEncadeadas = inserirItemTabelaListasEncadeadas(tabelaHashListasEncadeadas, item2);

    printf("Preço de item1: %.2f\n", buscarPrecoTabelaListasEncadeadas(tabelaHashListasEncadeadas, "item1"));
    printf("Preço de item2: %.2f\n", buscarPrecoTabelaListasEncadeadas(tabelaHashListasEncadeadas, "item2"));

    tabelaHashListasEncadeadas = removerItemTabelaListasEncadeadas(tabelaHashListasEncadeadas, "item1");
    printf("Preço de item1 após remoção: %.2f\n", buscarPrecoTabelaListasEncadeadas(tabelaHashListasEncadeadas, "item1"));

    // Testando as operações com a árvore binária de pesquisa
    NoArvore *arvore = NULL;
    arvore = inserirArvore(arvore, item1);
    arvore = inserirArvore(arvore, item2);

    printf("Preço de item1: %.2f\n", buscarPrecoArvore(arvore, "item1"));
    printf("Preço de item2: %.2f\n", buscarPrecoArvore(arvore, "item2"));

    int altura = calcularAlturaArvore(arvore);
    printf("Altura da árvore: %d\n", altura);

    // Libera a memória da árvore
    liberarArvore(arvore);

    return 0;
}
