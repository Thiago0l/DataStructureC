#include <stdio.h>

void preencher(int lista[], int tamanho) {
    printf("Digite %d números para preencher a lista: \n", tamanho);
    for (int i = 0; i < tamanho; i++) {
        printf("Digite o %dº valor: \n", i + 1);
        scanf("%d", &lista[i]);
    }
}

void printLista(int lista[], int tamanho) {
    printf("LISTA: \n");
    for (int i = 0; i < tamanho; i++) {
        printf("%d \n", lista[i]);
    }
}

void max(int lista[], int tamanho) {
    int maior = lista[0]; // Inicializa 'maior' com o primeiro elemento
    for (int i = 1; i < tamanho; i++) { // Começa do segundo elemento
        if (lista[i] > maior) {
            maior = lista[i];
        }
    }
    printf("O maior número da lista é: %d \n", maior);
}

int main() {
    int tamanho = 10;
    int lista[tamanho];
    
    preencher(lista, tamanho);
    printLista(lista, tamanho);
    max(lista, tamanho);
    
    return 0;
}
