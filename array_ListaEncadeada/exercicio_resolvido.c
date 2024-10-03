#include <stdio.h>
#include <stdlib.h>

// Definição da estrutura do nó da lista
typedef struct TElemento {
    int valor;
    struct TElemento *proximo;
} TElemento;

// Inicialização da lista
TElemento *inicio = NULL;

// Função para criar um novo nó
TElemento* criarElemento(int valor) {
    TElemento *novo = (TElemento *)malloc(sizeof(TElemento));
    novo->valor = valor;
    novo->proximo = NULL;
    return novo;
}

// Função para inserir um elemento de forma ordenada
void insereOrdenado(int valor) {
    TElemento *novo = criarElemento(valor);

    if (!inicio || inicio->valor >= valor) {
        novo->proximo = inicio;
        inicio = novo;
        return;
    }

    TElemento *atual = inicio;
    while (atual->proximo && atual->proximo->valor < valor) {
        atual = atual->proximo;
    }
    novo->proximo = atual->proximo;
    atual->proximo = novo;
}

// Função para exibir a lista
void exibeLista() {
    for (TElemento *atual = inicio; atual != NULL; atual = atual->proximo) {
        printf("%d ", atual->valor);
    }
    printf("\n");
}

// Função para deletar um elemento da lista
void deleta(int valor) {
    TElemento *atual = inicio;
    TElemento *anterior = NULL;

    while (atual && atual->valor != valor) {
        anterior = atual;
        atual = atual->proximo;
    }

    if (!atual) {
        printf("Elemento nao esta na lista\n");
        return;
    }

    if (anterior) {
        anterior->proximo = atual->proximo;
    } else {
        inicio = atual->proximo;
    }

    free(atual);
}

// Função para criar a lista inicial
void criaLista() {
    int valor;
    printf("Digite os numeros (-1 para encerrar):\n");
    while (1) {
        scanf("%d", &valor);
        if (valor == -1) break;
        insereOrdenado(valor);
    }
}

// Função principal
int main() {
    criaLista();
    printf("A lista encadeada é:\n");
    exibeLista();

    // Loop para continuar inserindo elementos de forma ordenada
    int continuar = 1;
    while (continuar) {
        int valorParaInserir;
        printf("Digite um valor para inserir na lista de forma ordenada: ");
        scanf("%d", &valorParaInserir);
        insereOrdenado(valorParaInserir);
        printf("A lista encadeada após a inserção é:\n");
        exibeLista();

        printf("Deseja inserir outro valor? (1 para sim, 0 para não): ");
        scanf("%d", &continuar);
    }

    // Liberar a memória alocada
    while (inicio) {
        TElemento *temp = inicio;
        inicio = inicio->proximo;
        free(temp);
    }

    return 0;
}
