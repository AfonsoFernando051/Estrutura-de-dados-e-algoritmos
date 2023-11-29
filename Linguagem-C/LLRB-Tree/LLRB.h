typedef struct node
{
    struct node *esq, *dir;
    int data;

    bool cor;
    bool wasRemoved;
} node;

node* criar(int data, bool cor);
node* rotateLeft(node* novoNode);
node* rotateRight(node* novoNode);
int eh_vermelho(node *novoNode);
void mudarCor(node *node1, node *node2);
node* inserir(node* novoNode, int data);
void print(node *node);
void pesquisaNode(node *node, int valor);
void removeNode(node *node, int valor);
